/*
** EPITECH PROJECT, 2023
** MIRROR-B-CCP-400-NAN-4-1-theplazza-andreas.le-tanter
** File description:
** IReception
*/

#include "Reception.hpp"
#include "../Parser/Parser.hpp"
#include "../Kitchen/Kitchen.hpp"
#include "../Pizza/Regina/ReginaPizza.hpp"

#include <iostream>
#include <unistd.h>

volatile sig_atomic_t gSignalStatus = 0;

/**
 * @brief signal handler
 * @details this function is used to handle the signal
 * @param signum the signal
 * @return void
*/
static void signalHandler(int signum)
{
    gSignalStatus = signum;
}

/**
 * @brief Construct a new Reception:: Reception object
 * @details this function create the mutex, the queue and open the file 
 * @param multiplier the multiplier for the cooking time
 * @param nbCooks the number of cooks
 * @param refillTime the time to refill the ingredients
*/
Reception::Reception(double multiplier, unsigned int nbCooks, unsigned int refillTime)
{
    m_is_running = true;
    sigemptyset(&m_sa.sa_mask);
    m_sa.sa_flags = 0;
    m_sa.sa_handler = signalHandler;
    sigaction(SIGINT, &m_sa, nullptr);
    m_multiplier = multiplier;
    m_nbCooks = nbCooks;
    m_refillTime = refillTime;
    m_file.open("Pizza.log", std::ios::out);
    m_Segment = boost::interprocess::managed_shared_memory(boost::interprocess::open_or_create, "SharedMemory", 65536);
    m_sharedPizza = m_Segment.construct<std::shared_ptr<IPizza>>("SharedPizza")(nullptr);
    waitCommands();
}

/**
 * @brief Destroy the Reception:: Reception object
 * @details this function close the file
*/
Reception::~Reception()
{
    m_file.close();
    m_Segment.destroy<std::shared_ptr<IKitchen>>("SharedPizza");
    boost::interprocess::shared_memory_object::remove("SharedMemory");
}

/**
 * @brief Wait for commands from the user
 * @details this function is the main loop that use the parser to get the pizza to cook in a vector
*/
void Reception::waitCommands()
{
    Parser parser;
    std::vector<std::shared_ptr<IPizza>> pizzas;

    while (m_is_running) {
        if (gSignalStatus == SIGINT) {
            m_is_running = false;
            break;
        }
        pizzas = parser.getInput();
        for (auto &i : pizzas) {
            savePizzaToLog(i);
            usleep(800);
            sendPizzaToKitchen(i);
        }
    }
}

/**
 * @brief Send the pizza to the queue
 * @details this function send the pizza to safe queue for the kitchen
 * @details this function check if the pizza is not null
 * @param pizza the pizza to send
*/
void Reception::savePizzaToLog(std::shared_ptr<IPizza> pizza)
{
    if (pizza == nullptr) {
        return;
    }
    try {
        m_file << "Pizza type : " << pizza->getType() << " size : " << pizza->getSize() << std::endl;
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
}

void Reception::createKitchen()
{
    pid_t pid = fork();

    if (pid == 0) {
        std::shared_ptr<IKitchen> kitchen = std::make_shared<Kitchen>(m_nbCooks, m_multiplier, m_refillTime);
        m_mutex.lock();
        m_mutex.unlock();
        while (kitchen->isExitNeeded() == false) {
            m_mutex.lock();
            std::shared_ptr<IPizza>* pizza = m_Segment.find<std::shared_ptr<IPizza>>("SharedPizza").first;
            if ((*pizza) != nullptr && kitchen->isKitchenFilled() == false && kitchen->checkPantry((*pizza)->getIngredients()) == true) {
                std::shared_ptr<IPizza> pizzaToCook = (*pizza);
                std::cout << "Pizza " << pizzaToCook->getType() << " is cooking" << std::endl;
                kitchen->addPizzaToPool(pizzaToCook);
                *pizza = nullptr;
            }
            m_mutex.unlock();
        }
        exit(0);
    } else if (pid == -1) {
        std::cerr << "Error while creating kitchen" << std::endl;
    }
}

void Reception::sendPizzaToKitchen(std::shared_ptr<IPizza> t_pizza)
{
    m_mutex.lock();
    std::shared_ptr<IPizza>* pizza = m_Segment.find<std::shared_ptr<IPizza>>("SharedPizza").first;

    *pizza = t_pizza;
    if (m_Segment.find<std::shared_ptr<IPizza>>("SharedPizza").first == nullptr) {
        m_mutex.unlock();
        return;
    }
    m_mutex.unlock();
    createKitchen();
}

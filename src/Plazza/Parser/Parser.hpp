/*
** EPITECH PROJECT, 2023
** plazza
** File description:
**
*/

#pragma once
#include "IParser.hpp"
#include <regex>

class Parser : public IParser {
public:
    Parser() = default;
    ~Parser() override = default;
    /**
     * @brief get input from user
     * @details get input from user, parse it, handle errors and create a vector of shared pointers of IPizza type
     * @return result of setPizza() : vector of shared pointers of IPizza type
     */
    std::vector<std::shared_ptr<IPizza>> getInput() override;
    /**
     * @brief set all pizzas contained in t_inputs
     * @param t_inputs string vector containing all inputs to set pizzas
     * @return vector of shared pointers of IPizza type
     */
    std::vector<std::shared_ptr<IPizza>> setPizzas(std::vector<std::string> t_inputs);
    /**
     * @brief set a Pizza, with a name and a size, and return it
     * @param t_pizzaName name of the pizza
     * @param t_pizzaSize size of the pizza
     * @return shared pointer of IPizza type
     */
    std::shared_ptr<IPizza> setPizza(const std::string& t_pizzaName, const std::string& t_pizzaSize);
    /**
     * @brief get a string from the input
     * @details get string from input, starting from index and terminating at delimiter or input end
     * @param t_input input from user
     * @param t_i input index
     * @return a string containing an input param
     */
    std::string getInputString(std::string t_input, size_t *t_i);
    /**
     * @brief check if a string is authorized
     * @details check if string passed as parameter match entries in different string vectors
     * @param t_inputParam parsed input parameter
     * @return a boolean
     */
    bool isAuthorized(const std::string& t_inputParam);
    /**
     * @brief check if a string is in a vector
     * @param t_vector reference vector
     * @param t_str_to_find string to find
     * @return a boolean
     */
    bool isInVector(std::vector<std::string> t_vector, const std::string& t_str_to_find);
    /**
     * @brief convert a string into a PizzaSize type
     * @param t_str pizza size as a string
     * @return a PizzaSize type
     */
    PizzaSize stringToPizzaSize(const std::string& t_str);
private:
    std::vector<std::string> m_authorizedPizzas =
        {"regina",
         "margarita",
         "americana",
         "fantasia"};
    std::vector<std::string> m_authorizedSizes =
        {"S",
         "M",
         "L",
         "XL",
         "XXL"};
protected:
};

/*
** EPITECH PROJECT, 2023
** Bootstrap-Plazza
** File description:
** ThreadClass
*/

#include <criterion/criterion.h>
#include <iostream>
#include <memory>
#include <unistd.h>
#include "../src/IThread/Thread.hpp"

static void *makeThreadWait(int seconds)
{
    sleep(seconds);

    return nullptr;
}



Test(IThread, Basic_Status)
{
    std::unique_ptr<IThread> thread = std::make_unique<Thread<decltype(makeThreadWait), int>>(makeThreadWait, 2);

    cr_assert_eq(thread->getThreadStatus(), ThreadStatus::RUNNING);
    thread->joinThread();
    cr_assert_eq(thread->getThreadStatus(), ThreadStatus::STOPPED);
}

Test(IThread, Stop_Thread)
{
    std::unique_ptr<IThread> thread = std::make_unique<Thread<decltype(makeThreadWait), int>>(makeThreadWait, 2);

    cr_assert_eq(thread->getThreadStatus(), ThreadStatus::RUNNING);
    thread->stopThread();
    cr_assert_eq(thread->getThreadStatus(), ThreadStatus::STOPPED);
}

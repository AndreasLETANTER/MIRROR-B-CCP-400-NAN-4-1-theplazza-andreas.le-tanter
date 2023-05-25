###############################BASE INFORMATION###################################
cmake_minimum_required(VERSION 3.17.0)
project("plazza" VERSION 0.1.0 LANGUAGES CXX)

###############################COMPILATION VARIABLES##############################
set(CMAKE_CXX_STANDARD 20)
set(NAME "plazza")
set(TEST_NAME "unit_tests")
set(CXX_FLAGS -Wall -Wextra -Werror)
###############################DIRECTORIES SRC####################################
set(SRC
    src/Timer/Timer.cpp
    src/IMutex/Mutex.cpp
    src/IConditionVariable/ConditionVariable.cpp
    src/IMutex/ScopedLock/ScopedLock.cpp
    src/Plazza/Parser/Parser.cpp
    src/Plazza/Reception/Reception.cpp
    src/Plazza/Pizza/APizza.cpp
    src/Plazza/Pizza/Margarita/MargaritaPizza.cpp
    src/Plazza/Pizza/Regina/ReginaPizza.cpp
    src/Plazza/Pizza/Americana/AmericanaPizza.cpp
    src/Plazza/Pizza/Fantasia/FantasiaPizza.cpp
    src/Plazza/Kitchen/Pantry/Pantry.cpp
    src/Plazza/Kitchen/Cook/CookRoutine.cpp
    src/Plazza/Kitchen/Bodyguard/BodyguardRoutine.cpp
    src/Plazza/Kitchen/Kitchen.cpp
)

set(MAIN
    src/main.cpp
)

set(TESTS
    tests/SafeQueueClass.cpp
    tests/ThreadClass.cpp
    tests/PizzaClass/AmericanaPizza.cpp
    tests/PizzaClass/FantasiaPizza.cpp
    tests/PizzaClass/MargaritaPizza.cpp
    tests/PizzaClass/ReginaPizza.cpp
    tests/KitchenClass/PantryClass/Pantry.cpp
    tests/KitchenClass/Kitchen.cpp
    tests/ParserClass.cpp
)

###############################COMPILATION MAIN PROGRAM###########################
add_compile_options(${CXX_FLAGS})
include_directories("/usr/local/include")
link_directories("/usr/local/lib")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
add_executable(${NAME} ${SRC} ${MAIN})

###############################COMPILATION TESTS##################################
find_library(CRITERION criterion)
add_executable(${TEST_NAME} ${SRC} ${TESTS})
target_link_libraries(${TEST_NAME} ${CRITERION})

###############################CUSTOM TARGETS#####################################
add_custom_target(fclean
    COMMAND make clean
    COMMAND find . -name "*~" -delete
    COMMAND find . -name "*.gcno" -delete
    COMMAND find . -name "*.gcda" -delete
    COMMAND find . -name "unit_test" -delete
    COMMAND find . -name "*.o" -delete
    COMMAND find . -name "*.so" -delete
    COMMAND find . -name "CMakeCache.txt" -delete
    COMMAND rm -rf CMakeFiles
    COMMAND find . -name "cmake_install.cmake" -delete
    COMMAND find . -name "Makefile" -delete
    COMMAND find . -name ${NAME} -delete
    COMMAND find . -name "*.a" -delete
    COMMAND find . -name "lib" -delete
    COMMENT "Clean the project and the binary"
)

#set the target to recompile the project
add_custom_target(re
    COMMAND make clean
    COMMAND make
    COMMENT "Recompiling the project"
)

#set the target to run the tests
add_custom_target(tests_run
    COMMAND make ${TEST_NAME}
    COMMAND ./${TEST_NAME}
    COMMENT "Running unit tests"
)

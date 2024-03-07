// delay.h

#ifndef DELAY_H
#define DELAY_H

#include <thread>
#include <chrono>

/**
 * Delays the program execution for the specified number of milliseconds. (1000 milliseconds = 1 second)
 *
 * @param number_of_milliseconds the number of milliseconds to delay
 *
 * @return None
 *
 * @throws None
 */
void delay(int number_of_milliseconds)
{
    std::this_thread::sleep_for(std::chrono::milliseconds(number_of_milliseconds));
}

#endif
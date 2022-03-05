#pragma once

#include <iostream>
#include <iomanip>
#include <chrono>
#include <ctime>

using namespace std;

class StopWatch
{
private:
    std::clock_t c_start;
    std::chrono::time_point<std::chrono::high_resolution_clock> t_start;

public:
    StopWatch()
    {
        c_start = std::clock();
        t_start = std::chrono::high_resolution_clock::now();
    }

    void elapsedTime()
    {
        std::clock_t c_end = std::clock();
        auto t_end = std::chrono::high_resolution_clock::now();

        // print CPU time used
        std::cout << std::fixed << std::setprecision(2) << "CPU time used: " << 1000.0 * (c_end - c_start) / CLOCKS_PER_SEC << " ms" << endl;
    }
};
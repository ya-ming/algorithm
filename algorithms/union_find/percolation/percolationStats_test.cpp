#include <gtest/gtest.h>

#include "percolationStats.h"
#include "../../utility/stopWatch.h"

using namespace std;

namespace union_find
{

TEST(union_find, tests)
{
    cout << "200x100" << endl;
    PercolationStats percolationStats(200, 100);
    percolationStats.compute();
    percolationStats.print();

    cout << endl << "200x100" << endl;
    percolationStats = PercolationStats(200, 100);
    percolationStats.compute();
    percolationStats.print();

    cout << endl << "2x10000" << endl;
    percolationStats = PercolationStats(2, 10000);
    percolationStats.compute();
    percolationStats.print();

    cout << endl << "2x100000" << endl;
    percolationStats = PercolationStats(2, 100000);
    percolationStats.compute();
    percolationStats.print();
}

TEST(union_find, measureRunningTimeByDoublingTheNumberOfSites)
{
    // based on the measurement, double the number of sites, quadruple the processing time
    cout << "100x100" << endl;
    PercolationStats percolationStats(100, 100);
    StopWatch stopWatch;
    percolationStats.compute();
    stopWatch.elapsedTime();
    percolationStats.print();

    cout << endl << "200x100" << endl;
    percolationStats = PercolationStats(200, 100);
    stopWatch = StopWatch();
    percolationStats.compute();
    stopWatch.elapsedTime();
    percolationStats.print();

    cout << endl << "400x100" << endl;
    percolationStats = PercolationStats(400, 100);
    stopWatch = StopWatch();
    percolationStats.compute();
    stopWatch.elapsedTime();
    percolationStats.print();
}

TEST(union_find, measureRunningTimeByDoublingTheNumberOfTrails)
{
    // based on the measurement, double the number of trails also double the processing time
    cout << "100x100" << endl;
    PercolationStats percolationStats(100, 100);
    StopWatch stopWatch;
    percolationStats.compute();
    stopWatch.elapsedTime();
    percolationStats.print();

    cout << endl << "100x200" << endl;
    percolationStats = PercolationStats(100, 200);
    stopWatch = StopWatch();
    percolationStats.compute();
    stopWatch.elapsedTime();
    percolationStats.print();

    cout << endl << "100x400" << endl;
    percolationStats = PercolationStats(100, 400);
    stopWatch = StopWatch();
    percolationStats.compute();
    stopWatch.elapsedTime();
    percolationStats.print();
}

}
#include <fstream>
#include <gtest/gtest.h>
#include "three_sum.h"
#include "../utility/stopWatch.h"

namespace analysis_of_algorithms
{

TEST(analysis_of_algorithms, bruteForce_1k)
{
    ThreeSum ob;

    vector<int> a;

    std::ifstream in("algorithms/inputs/1Kints.txt");
    int x;
    while (in >> x)
    {
        a.push_back(x);
    }

    StopWatch stopWatch;
    int count = ob.bruteForce(a);
    stopWatch.elapsedTime();

    cout << "count = " << count << endl;
}

TEST(analysis_of_algorithms, bruteForce_2k)
{
    ThreeSum ob;
    vector<int> a;
    std::ifstream in("algorithms/inputs/2Kints.txt");
    int x;

    while (in >> x)
    {
        a.push_back(x);
    }

    StopWatch stopWatch;
    int count = ob.bruteForce(a);
    stopWatch.elapsedTime();

    cout << "count = " << count << endl;
}

TEST(analysis_of_algorithms, bruteForce_4k)
{
    ThreeSum ob;
    vector<int> a;
    std::ifstream in("algorithms/inputs/4Kints.txt");
    int x;

    while (in >> x)
    {
        a.push_back(x);
    }

    StopWatch stopWatch;
    int count = ob.bruteForce(a);
    stopWatch.elapsedTime();

    cout << "count = " << count << endl;
}

TEST(analysis_of_algorithms, fast)
{
    ThreeSum ob;

    vector<int> a{30, -40, -20, -10, 40, 0, 10, 5};

    StopWatch stopWatch;
    int count = ob.fast(a);
    stopWatch.elapsedTime();

    cout << "count = " << count << endl;
}


TEST(analysis_of_algorithms, fast_1k)
{
    ThreeSum ob;

    vector<int> a;

    std::ifstream in("algorithms/inputs/1Kints.txt");
    int x;
    while (in >> x)
    {
        a.push_back(x);
    }

    StopWatch stopWatch;
    int count = ob.fast(a);
    stopWatch.elapsedTime();

    cout << "count = " << count << endl;
}

TEST(analysis_of_algorithms, fast_2k)
{
    ThreeSum ob;
    vector<int> a;
    std::ifstream in("algorithms/inputs/2Kints.txt");
    int x;

    while (in >> x)
    {
        a.push_back(x);
    }

    StopWatch stopWatch;
    int count = ob.fast(a);
    stopWatch.elapsedTime();

    cout << "count = " << count << endl;
}

TEST(analysis_of_algorithms, fast_4k)
{
    ThreeSum ob;
    vector<int> a;
    std::ifstream in("algorithms/inputs/4Kints.txt");
    int x;

    while (in >> x)
    {
        a.push_back(x);
    }

    StopWatch stopWatch;
    int count = ob.fast(a);
    stopWatch.elapsedTime();

    cout << "count = " << count << endl;
}

}
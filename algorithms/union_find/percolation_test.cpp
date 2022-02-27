#include <gtest/gtest.h>

#include "percolation.h"

using namespace std;

namespace union_find
{

TEST(union_find, 4_4)
{
    unsigned int n = 4;
    //   0 
    //   1   2   3   4 
    //   5   6   7   8 
    //   9  10  11  12 
    //  13  14  15  16 
    //  17 

    Percolation percolation(n);
    percolation.print();

    percolation.open(3, 3);
    percolation.print();

    percolation.open(2, 3);
    percolation.print();

    percolation.open(1, 4);
    percolation.print();

    percolation.open(1, 3);
    percolation.print();

    percolation.open(4, 3);
    percolation.print();

    percolation.open(4, 4);
    percolation.print();

    EXPECT_TRUE(percolation.percolates());
}

TEST(union_find, generateRowCol)
{
    unsigned int n = 20;
    random_device rd;  //Will be used to obtain a seed for the random number engine
    mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
    uniform_int_distribution<> distrib(1, n);

    unsigned int row = distrib(gen);
    unsigned int col = distrib(gen);

    cout << "row = " << row << endl;
    cout << "col = " << col << endl;
}


TEST(union_find, 20_20)
{
    unsigned int n = 20;
    random_device rd;  //Will be used to obtain a seed for the random number engine
    mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
    uniform_int_distribution<> distrib(1, n);

    Percolation percolation(n);
    percolation.print();

    unsigned int count = 0;
    while (!percolation.percolates())
    {
        unsigned int row = distrib(gen);
        unsigned int col = distrib(gen);

        while (percolation.isOpen(row, col)) {
            row = distrib(gen);
            col = distrib(gen);
            // cout << "try row = " << row << ", col = " << col << endl;
        }

        cout << "Interation " << count << ", row = " << row << ", col = " << col << endl;

        percolation.open(row, col);

        count++;
    }

    cout << "Interations = " << count << endl;
    percolation.print();
}

}
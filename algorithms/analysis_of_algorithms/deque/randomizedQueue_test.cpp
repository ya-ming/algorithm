#include <fstream>
#include <gtest/gtest.h>
#include "randomizedQueue.h"
#include "../../utility/stopWatch.h"

namespace deque
{

TEST(randomizedQueue, dequeue)
{
    RandomizedQueue<int> randomizedQueue;
    EXPECT_EQ(0, randomizedQueue.size());

    randomizedQueue.enqueue(1);
    randomizedQueue.enqueue(2);
    randomizedQueue.enqueue(3);
    randomizedQueue.enqueue(4);

    EXPECT_EQ(4, randomizedQueue.size());

    int item = randomizedQueue.dequeue();
    cout << item << ", ";
    item = randomizedQueue.dequeue();
    cout << item << ", ";
    item = randomizedQueue.dequeue();
    cout << item << ", ";
    item = randomizedQueue.dequeue();
    cout << item << endl;
    EXPECT_EQ(0, randomizedQueue.size());
}

TEST(randomizedQueue, sample)
{
    RandomizedQueue<int> randomizedQueue;
    EXPECT_EQ(0, randomizedQueue.size());

    randomizedQueue.enqueue(1);
    randomizedQueue.enqueue(2);
    randomizedQueue.enqueue(3);
    randomizedQueue.enqueue(4);

    EXPECT_EQ(4, randomizedQueue.size());

    int item = randomizedQueue.sample();
    cout << item << ", ";
    item = randomizedQueue.sample();
    cout << item << ", ";
    item = randomizedQueue.sample();
    cout << item << ", ";
    item = randomizedQueue.sample();
    cout << item << endl;
    EXPECT_EQ(4, randomizedQueue.size());
}

TEST(randomizedQueue, permutation)
{
    RandomizedQueue<string> randomizedQueue;
    EXPECT_EQ(0, randomizedQueue.size());

    // AA BB BB BB BB BB CC CC
    randomizedQueue.enqueue("AA");
    randomizedQueue.enqueue("BB");
    randomizedQueue.enqueue("BB");
    randomizedQueue.enqueue("BB");
    randomizedQueue.enqueue("BB");
    randomizedQueue.enqueue("BB");
    randomizedQueue.enqueue("CC");
    randomizedQueue.enqueue("CC");

    EXPECT_EQ(8, randomizedQueue.size());

    string item = randomizedQueue.dequeue();
    cout << item << ", ";
    item = randomizedQueue.dequeue();
    cout << item << ", ";
    item = randomizedQueue.dequeue();
    cout << item << ", ";
    item = randomizedQueue.dequeue();
    cout << item << endl;
    EXPECT_EQ(4, randomizedQueue.size());
}

}
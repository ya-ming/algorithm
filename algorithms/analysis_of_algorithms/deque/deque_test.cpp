#include <fstream>
#include <gtest/gtest.h>
#include "deque.h"
#include "../../utility/stopWatch.h"

namespace deque
{

TEST(deque, basic)
{
    Deque<int> deque;
    EXPECT_EQ(0, deque.size());

    deque.addFirst(1);
    deque.addFirst(2);

    deque.addLast(3);
    deque.addLast(4);

    EXPECT_EQ(4, deque.size());

    EXPECT_EQ(2, deque.removeFirst());
    EXPECT_EQ(1, deque.removeFirst());

    EXPECT_EQ(4, deque.removeLast());
    EXPECT_EQ(3, deque.removeLast());

    EXPECT_EQ(0, deque.size());
}

TEST(deque, basic2)
{
    Deque<int> deque;
    EXPECT_EQ(0, deque.size());

    deque.addLast(1);
    deque.addLast(2);

    deque.addFirst(3);
    deque.addFirst(4);

    EXPECT_EQ(4, deque.size());

    EXPECT_EQ(2, deque.removeLast());
    EXPECT_EQ(1, deque.removeLast());

    EXPECT_EQ(4, deque.removeFirst());
    EXPECT_EQ(3, deque.removeFirst());

    EXPECT_EQ(0, deque.size());
}

TEST(deque, iterator)
{
    Deque<int> deque;
    EXPECT_EQ(0, deque.size());

    deque.addLast(1);
    deque.addLast(2);

    deque.addFirst(3);
    deque.addFirst(4);

    for (auto it = deque.begin(); it != deque.end(); it++)
    {
        cout << *it << endl;
    }
    auto it = deque.begin();
    EXPECT_EQ(4, *it);
    it++;
    EXPECT_EQ(3, *it);
    it++;
    EXPECT_EQ(1, *it);
    it++;
    EXPECT_EQ(2, *it);
    it++;
    EXPECT_EQ(deque.end(), it);
}

TEST(deque, exception)
{
    Deque<int> deque;
    EXPECT_EQ(0, deque.size());

    deque.addFirst(1);
    deque.addLast(2);

    deque.removeFirst();
    deque.removeFirst();

    try
    {
        deque.removeFirst();
    }
    catch(const std::exception& e)
    {
        EXPECT_EQ(e.what(), std::string("NoSuchElementException"));
    }
    
    try
    {
        deque.removeLast();
    }
    catch(const std::exception& e)
    {
        EXPECT_EQ(e.what(), std::string("NoSuchElementException"));
    }

    auto it = deque.begin();

    try
    {
        it++;
    }
    catch(const std::exception& e)
    {
        EXPECT_EQ(e.what(), std::string("NoSuchElementException"));
    }
    
    try
    {
        it--;
    }
    catch(const std::exception& e)
    {
        EXPECT_EQ(e.what(), std::string("NoSuchElementException"));
    }
}

TEST(deque, string)
{
    Deque<string> deque;
    EXPECT_EQ(0, deque.size());

    deque.addLast("1");
    deque.addLast("2");

    deque.addFirst("3");
    deque.addFirst("4");

    for (auto it = deque.begin(); it != deque.end(); it++)
    {
        cout << *it << endl;
    }
    auto it = deque.begin();
    EXPECT_EQ("4", *it);
    it++;
    EXPECT_EQ("3", *it);
    it++;
    EXPECT_EQ("1", *it);
    it++;
    EXPECT_EQ("2", *it);
    it++;
    EXPECT_EQ(deque.end(), it);
}

}
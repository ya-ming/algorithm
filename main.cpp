#include <gtest/gtest.h>

#include "searching/linearSearchTest.cpp"
#include "searching/binarySearchTest.cpp"
#include "searching/jumpSearchTest.cpp"
#include "searching/exponentialSearchTest.cpp"
#include "searching/ternarySearchTest.cpp"
#include "searching/listSearchTest.cpp"
#include "searching/fibonacciSearchTest.cpp"
#include "searching/searchTest.cpp"
#include "searching/challenges/searchingChallengesTest.cpp"

#include "algorithms\union_find\quick_find_uf_test.cpp"
#include "algorithms\union_find\quick_union_uf_test.cpp"

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv); 
    return RUN_ALL_TESTS();
}
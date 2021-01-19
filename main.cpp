#include <gtest/gtest.h>

#include "searching/linearSearchTest.cpp"
#include "searching/binarySearchTest.cpp"
#include "searching/jumpSearchTest.cpp"

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv); 
    return RUN_ALL_TESTS();
}
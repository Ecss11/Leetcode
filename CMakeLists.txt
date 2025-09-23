cmake_minimum_required(VERSION 4.0)
project(Leetcode)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Leetcode
        TwoSum.cpp
        MedianOfTwoSortedArrays.cpp
        BestTimeToBuyAndSellStock.cpp
        ProductOfArrayExceptSelf.cpp
)

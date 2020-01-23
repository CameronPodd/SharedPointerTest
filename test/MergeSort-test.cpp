#include <iostream>
#include <memory>
#include <vector>
#include <cstdlib>

#include "gtest/gtest.h"
#include "../src/MergeSort.h"
#include "helpers.h"

TEST(SortInt, SmallMerge)
{
    // Arrange
    auto unsorted = std::make_shared<std::vector<int>>();
    // Act
    unsorted->push_back(0);
    unsorted->push_back(2);
    unsorted->push_back(1);
    auto sortedCopy = std::make_shared<std::vector<int>>();
    sortedCopy->push_back(0);
    sortedCopy->push_back(1);
    sortedCopy->push_back(2);
    auto sorted = sort::MergeSort<int>(unsorted, numberComparatorGreater<int>);
    // Assert
    EXPECT_EQ(sorted->size(), sortedCopy->size());
    for (size_t i = 0; i < sorted->size(); i++)
    {
        EXPECT_EQ(sorted->at(i), sortedCopy->at(i));
    }
}

TEST(SortInt, EmptyMerge)
{
    // Arrange
    auto unsorted = std::make_shared<std::vector<int>>();
    // Act
    auto sorted = sort::MergeSort<int>(unsorted, numberComparatorGreater<int>);
    // Assert
    EXPECT_EQ(sorted->size(), 0);
    EXPECT_TRUE(isSorted<int>(sorted, numberComparatorGreater<int>));
}

TEST(SortInt, LargeMerge)
{
    const int SIZE = 1000000;
    // Arrange
    auto unsorted = std::make_shared<std::vector<int>>();
    // Act
    for (size_t i = 0; i < SIZE; i++) { unsorted->push_back(rand()); }
    auto sorted = sort::MergeSort<int>(unsorted, numberComparatorGreater<int>);
    // Assert
    EXPECT_EQ(sorted->size(), SIZE);
    EXPECT_TRUE(isSorted<int>(sorted, numberComparatorGreater<int>));
}

#include <vector>

#include "gtest/gtest.h"
#include "../src/MergeSort.h"

template <typename T>
auto numberComparatorGreater = [](T a, T b)
{
    return a > b;
};

TEST(SortSucessful, SmallMerge)
{
    // Arrange
    auto unsorted = std::make_shared<std::vector<int>>();
    // Act
    unsorted->push_back(0);
    unsorted->push_back(2);
    unsorted->push_back(1);
    auto unsortedCopy = std::vector<int>(*unsorted);
    auto sorted = sort::MergeSort<int>(unsorted, numberComparatorGreater<int>);
    // Assert
    EXPECT_EQ(sorted->size(), unsortedCopy.size());
    for (size_t i = 0; i < sorted->size(); i++)
    {
        EXPECT_EQ(sorted->at(i), unsortedCopy.at(i));
    }
}

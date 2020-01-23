#pragma once
#include "../src/MergeSort.h"

template <typename T>
auto numberComparatorGreater = [](T a, T b)
{
    return a > b;
};

template <typename T>
bool isSorted(sort::Vector<T> input, sort::Comparator<T> greater)
{
    if (input->size() < 1) { return true; }
    for (auto it = input->begin(); it < (input->end() - 1); ++it)
    {
        if (greater(*it, *it + 1)) { return false; }
    }
    return true;
}

#pragma once

#include <algorithm>
#include <memory>
#include <vector>
#include <functional>

namespace sort
{
    template<typename T>
    using Vector = std::shared_ptr<std::vector<T>>;

    template<typename T>
    using Comparator = std::function<bool (T, T)>;

    template <typename T>
    Vector<T> MergeSort(Vector<T>, Comparator<T>);

    template <typename T>
    Vector<T> Merge(Vector<T>, Vector<T>, Comparator<T>);
}

template <typename T>
sort::Vector<T> sort::MergeSort(sort::Vector<T> input, sort::Comparator<T> greater)
{
    if (input->size() <= 1)
    {
        return input;
    }
    auto left = std::make_shared<std::vector<T>>(input->begin(), input->begin() + input->size() / 2);
    auto right = std::make_shared<std::vector<T>>(input->begin() + input->size() / 2, input->end());
    left = MergeSort(left, greater);
    right = MergeSort(right, greater);
    return sort::Merge(left, right, greater);
}

template <typename T>
sort::Vector<T> sort::Merge(sort::Vector<T> left, sort::Vector<T> right, sort::Comparator<T> greater)
{
    auto result = std::make_shared<std::vector<T>>();
    auto leftIt = left->begin();
    auto rightIt = right->begin();

    while (leftIt < left->end() && rightIt < right->end())
    {
        if (!greater(*leftIt, *rightIt))
        {
            result->push_back(*leftIt);
            ++leftIt;
        } else {
            result->push_back(*rightIt);
            ++rightIt;
        }
    }

    for (; leftIt < left->end(); ++leftIt) { result->push_back(*leftIt); }
    for (; rightIt < right->end(); ++rightIt) { result->push_back(*rightIt); }

    return result;
}

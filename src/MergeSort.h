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
}

template <typename T>
sort::Vector<T> sort::MergeSort(sort::Vector<T> input, sort::Comparator<T> greater)
{
    return input;
}

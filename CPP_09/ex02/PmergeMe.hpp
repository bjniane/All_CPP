#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <algorithm>
#include <cmath>
#include <cstddef>
#include <iostream>
#include <vector>
#include <deque>

void    mergeByVector(const std::vector<int>& vec);
void    mergeByDeque(const std::deque<int>& vec);
int jacobsthal(int n);

template <typename T>
void    binarySearch(T& sorted, int value, int maxIndex)
{
    maxIndex = std::min(maxIndex, static_cast<int>(sorted.size() - 1));

    typename T::iterator begin = sorted.begin();
    typename T::iterator end = sorted.begin() + maxIndex + 1;
    
    typename T::iterator pos = std::lower_bound(begin, end,  value);
    sorted.insert(pos, value);
}

template <typename container>
void    mergeVec(container& left, container& right, container& vec)
{
    size_t i = 0;
    size_t j = 0;
    size_t k = 0;
    while (i < left.size() && j < right.size())
    {
        if (left[i].first <= right[j].first)
            vec[k++] = left[i++];
        else
            vec[k++] = right[j++];
    }
    while (i < left.size())
        vec[k++] = left[i++];
    while (j < right.size())
        vec[k++] = right[j++];
}

template <typename container>
void    mergeSort(container& arr)
{
    if (arr.size() <= 1)
        return;
    int mid = arr.size() / 2;
    container left(arr.begin(), arr.begin() + mid);
    container right(arr.begin() + mid, arr.end());
    mergeSort(left);
    mergeSort(right);
    mergeVec(left, right, arr);
}

template <typename container>
container getJacobsthalSequence(int value)
{
    container jacob;
    size_t i = 2;
    while (true)
    {
        if (jacobsthal(i) >= value)
        {
            jacob.push_back(jacobsthal(i));
            break;
        }
        jacob.push_back(jacobsthal(i));
        i++;
    }
    return jacob;
}

template <typename container>
container    fullInsertionOrder(container& jacob, int value)
{
    container full;
    if (jacob.empty() || jacob.size() < 2)
        return full;
    for (size_t i = 1; i < jacob.size(); ++i)
    {
        int current = jacob[i];
        int prev = jacob[i - 1];
        
        while (current > prev)
        {
            if (current <= value && std::find(full.begin(), full.end(), current) == full.end())
                full.push_back(current);
            current--;
        }
    }
    return full;
}

template <typename container1, typename container2>
container1   calculteBatches(const container2& insertionOrder, const container2& jacob)
{
    container1 batches;

    for (size_t i = 1; i < jacob.size(); i++)
    {
        int prev = jacob[i - 1];
        int current = jacob[i];

        int start = prev + 1;
        int end = current;
        container2 batch;
        for (size_t j = 0; j < insertionOrder.size(); j++)
        {
            int index = insertionOrder[j];
            if (index >= start && index <= end)
                batch.push_back(index);
        }
        if (!batch.empty())
            batches.push_back(batch);
    }
    return batches;
}

#endif
#include "PmergeMe.hpp"
#include <algorithm>
#include <cmath>
#include <cstddef>
#include <ctime>
#include <deque>
#include <vector>

int jacobsthal(int n)
{
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else
        return jacobsthal(n - 1) + 2 * jacobsthal(n - 2);
}

void    mergeByVector(const std::vector<int>& vec)
{
    clock_t start = clock();
    if (vec.size() < 2)
        return;
    std::vector< std::pair<int, int> > pairs;
    for (size_t i = 0; i + 1 < vec.size(); i += 2)
    {
        pairs.push_back(std::make_pair(vec[i], vec[i + 1]));
    }
    int left = -1;
    if (vec.size() % 2 != 0)
        left = vec.back();
    
    for (size_t i = 0; i < pairs.size(); i++)
    {
        if (pairs[i].first < pairs[i].second)
            std::swap(pairs[i].first, pairs[i].second);
    }

    mergeSort(pairs);
    std::vector<int> largest;
    std::vector<int> lowest;
    for (size_t i = 0; i < pairs.size(); i++)
    {
        largest.push_back(pairs[i].first);
        lowest.push_back(pairs[i].second);
    }
    largest.insert(largest.begin(), lowest.front());

    std::vector<int> jacob = getJacobsthalSequence< std::vector<int> >(lowest.size());

    std::vector<int> insertionOrder = fullInsertionOrder(jacob, lowest.size());

    std::vector< std::vector<int> > batches = calculteBatches< std::vector< std::vector<int> > >(insertionOrder, jacob);

    for (size_t i = 0; i < batches.size(); i++)
    {
        int maxIndex = std::pow(2, (i + 2)) - 1;
        for (size_t j = 0; j < batches[i].size(); j++)
        {
            int idx = batches[i][j];
            idx--;
            binarySearch(largest, lowest[idx], maxIndex);
        }
    }

    if (left != -1)
        binarySearch(largest, left, largest.size());

    clock_t end = clock();
    std::cout << "After: ";
    for (size_t i = 0; i < largest.size(); i++)
        std::cout << largest[i] << ' ';
    std::cout << std::endl;
    
    double duration = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1e6;
    std::cout << "Time to process a range of " << vec.size() << " elements with std::vector : " << duration << " us" << std::endl;

}

//sort by deque

void    mergeByDeque(const std::deque<int>& vec)
{
    clock_t start = clock();
    if (vec.size() < 2) 
        return;
    std::deque< std::pair<int, int> > pairs;
    for (size_t i = 0; i + 1 < vec.size(); i += 2)
    {
        pairs.push_back(std::make_pair(vec[i], vec[i + 1]));
    }
    int left = -1;
    if (vec.size() % 2 != 0)
        left = vec.back();
    
    for (size_t i = 0; i < pairs.size(); i++)
    {
        if (pairs[i].first < pairs[i].second)
            std::swap(pairs[i].first, pairs[i].second);
    }

    mergeSort(pairs);
    std::deque<int> largest;
    std::deque<int> lowest;
    for (size_t i = 0; i < pairs.size(); i++)
    {
        largest.push_back(pairs[i].first);
        lowest.push_back(pairs[i].second);
    }
    largest.insert(largest.begin(), lowest.front());

    std::deque<int> jacob = getJacobsthalSequence< std::deque<int> >(lowest.size());

    std::deque<int> insertionOrder = fullInsertionOrder(jacob, lowest.size());

    std::deque< std::deque<int> > batches = calculteBatches< std::deque< std::deque<int> > >(insertionOrder, jacob);

    for (size_t i = 0; i < batches.size(); i++)
    {
        int maxIndex = std::pow(2, (i + 2)) - 1;
        for (size_t j = 0; j < batches[i].size(); j++)
        {
            int idx = batches[i][j];
            idx--;
            binarySearch(largest, lowest[idx], maxIndex);
        }
    }

    if (left != -1)
        binarySearch(largest, left, largest.size());

    clock_t end = clock();

    double duration = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1e6;
    std::cout << "Time to process a range of " << vec.size() << " elements with std::deque : " << duration << " us" << std::endl;
}
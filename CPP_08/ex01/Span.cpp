#include "Span.hpp"
#include <cstddef>
#include <stdexcept>

Span::Span()
    : N(0)
{
}

Span::Span(unsigned int n)
    : N(n)
{
}

Span::Span(const Span& src)
    : N(src.N), arr(src.arr)
{
}

Span& Span::operator=(const Span& rhs)
{
    if (this != &rhs)
    {
        N = rhs.N;
        arr = rhs.arr;
    }
    return *this;
}

Span::~Span()
{
}

void    Span::addNumber(int n)
{
    if (arr.size() >= N)
        throw std::overflow_error("It's full!");
    arr.push_back(n);
}

int Span::shortestSpan()
{
    if (arr.size() < 2)
        throw std::runtime_error("Need at least two elements!");
    std::vector<int> copy;
    std::copy(arr.begin(), arr.end(), std::back_inserter(copy));
    std::sort(copy.begin(), copy.end());
    int shortest = copy[1] - copy[0];
    for (size_t i = 1; i < copy.size() - 1; i++)
    {
        int current = copy[i + 1] - copy[i];
        if (current < shortest)
            shortest = current;
    }
    return shortest;
}

int Span::longestSpan()
{
    if (arr.size() < 2)
        throw std::runtime_error("Need at least two elements!");
    std::vector<int> copy;
    std::copy(arr.begin(), arr.end(), std::back_inserter(copy));
    std::sort(copy.begin(), copy.end());
    return copy.back() - copy.front();
}
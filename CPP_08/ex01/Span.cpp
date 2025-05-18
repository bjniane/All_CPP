#include "Span.hpp"
#include <cstddef>

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
    std::sort(arr.begin(), arr.end());
    int shortest = arr[1] - arr[0];
    for (size_t i = 1; i < arr.size() - 1; i++)
    {
        int current = arr[i + 1] - arr[i];
        if (current < shortest)
            shortest = current;
    }
    return shortest;
}

int Span::longestSpan()
{
    return arr[arr.size() - 1] - arr[0];
}
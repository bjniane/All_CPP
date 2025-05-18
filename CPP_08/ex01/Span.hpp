#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>

class Span 
{
    private:
        unsigned int N;
        std::vector<int> arr;
    public:
        Span();
        Span(unsigned int n);
        Span(const Span& src);
        Span& operator=(const Span& rhs);
        ~Span();

        template<typename T>
        void    addRange(T first, T last)
        {
            arr.insert(arr.end(), first, last);
        }

        void    addNumber(int n);
        int shortestSpan();
        int longestSpan();
};

#endif
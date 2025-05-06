#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <stdexcept>

template<typename T>
class Array
{
    private:
        int n;
        T* arr;
    public:
        Array() {arr = new T;}
        Array(int length)
        {
            n = length;
            arr = new T[n];
        }
        Array(const Array& src)
            : n(src.n)
        {
            arr = new T[n];
            for (int i = 0; i < n; i++)
                arr[i] = src.arr[i];
        }
        Array&  operator=(const Array& rhs)
        {
            if (this != &rhs)
            {
                n = rhs.n;
                delete [] arr;
                arr = new T[n];
                for (int i = 0; i < n; i++)
                    arr[i] = rhs.arr[i];
            }
            return *this;
        }
        ~Array() {delete [] arr;}
        T&  operator[](int index)
        {
            if (index < 0 || index >= n)
                throw std::out_of_range("Index is out of bounds!");
            return arr[index];
        }

        int size() const {return n;}
};

#endif
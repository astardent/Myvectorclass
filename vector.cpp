#include<iostream>

template <typename T>
class Myvector
{
    private:
    T* data;
    T capacity;
    T current_size;
};
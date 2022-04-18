//
// Created by thero on 06.03.2022.
//

#ifndef SDIZO_PROJ_DATASTRUCT_HPP
#define SDIZO_PROJ_DATASTRUCT_HPP
#include <iostream>
#include <vector>
#include ".//Element.hpp"

template<typename T>
class DataStruct // abstract
{
protected:
    size_t num_of_elements;
    T* arr = nullptr;
public:
    DataStruct() : num_of_elements{0}
    {}
    virtual ~DataStruct()= default;

    virtual void push_back(T val) = 0;
    virtual void pop_back() = 0;
    virtual void push_front(T val) = 0;
    virtual void pop_front() = 0;
    virtual void add(T val, size_t index) = 0;
    virtual void erase(size_t index) = 0;
    virtual void clear() = 0;

    virtual void print()
    {
        std::cout << "Elements in Array:\n";
        for(int i = 0; i < num_of_elements; i++)
        {
            std::cout << arr[i] << std::endl;
        }
    }

    const size_t &length(){return num_of_elements;};
    virtual const Element<T> *find(const T& key) = 0;
    virtual const Element<T> * rfind(const T& key) = 0;

    virtual const T& operator[] (int index) const = 0;
    DataStruct& operator= (const DataStruct&) = delete;
    virtual DataStruct& operator= (const std::vector<T>&) = 0;
};

#endif //SDIZO_PROJ_DATASTRUCT_HPP

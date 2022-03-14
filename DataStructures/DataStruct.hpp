//
// Created by thero on 06.03.2022.
//

#ifndef SDIZO_PROJ_DATASTRUCT_HPP
#define SDIZO_PROJ_DATASTRUCT_HPP
#include <iostream>

template<typename T>
class DataStruct // abstract
{
protected:
    unsigned int num_of_elements;
    T* arr;
public:
    DataStruct() : num_of_elements{0}
    {}

    virtual void push_back(T val) = 0;
    virtual void pop_back() = 0;
    virtual void push_front(T val) = 0;
    virtual void pop_front() = 0;
    virtual void put(T val, size_t index) = 0;
    virtual void erase(size_t index) = 0;

    virtual void print()
    {
        std::cout << "Elements in structure:\n";
        for(int i = 0; i < num_of_elements; i++)
        {
            std::cout << arr[i] << std::endl;
        }
    }

    const unsigned int &length(){return num_of_elements;};

    DataStruct& operator= (const DataStruct&) = delete;
};

#endif //SDIZO_PROJ_DATASTRUCT_HPP

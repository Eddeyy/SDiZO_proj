//
// Created by thero on 06.03.2022.
//

#ifndef SDIZO_PROJ_DYNAMICARRAY_HPP
#define SDIZO_PROJ_DYNAMICARRAY_HPP
#include "../DataStruct.hpp"
#include "ArrayElement.hpp"

template<typename T>
class DynamicArray : public DataStruct<T>
{
public:

    DynamicArray();
    virtual ~DynamicArray();

    void push_back(T val) override;
    void push_front(T val) override;
    void add(T val, size_t index) override;
    void pop_back() override;
    void pop_front() override;
    void erase(size_t index) override;

    const Element<T> *find(const T& key) override;
    const Element<T> *rfind(const T& key) override;

    void print() override;

    T& operator[] (int index);

    DynamicArray(const DynamicArray& origin);
    DynamicArray& operator= (const DynamicArray& origin);
};


#endif //SDIZO_PROJ_DYNAMICARRAY_HPP

//
// Created by thero on 06.03.2022.
//

#ifndef SDIZO_PROJ_DYNAMICARRAY_HPP
#define SDIZO_PROJ_DYNAMICARRAY_HPP
#include "../DataStruct.hpp"

template<typename T>
class DynamicArray : public DataStruct<T>
{
public:

    DynamicArray();
    ~DynamicArray();

    void push_back(T val) override;
    void push_front(T val) override;
    void put(T val, int index) override;
    void pop_back() override;
    void pop_front() override;
    void erase(int index) override;


    T& operator[] (int index);

    DynamicArray(const DynamicArray& origin);
    DynamicArray& operator= (const DynamicArray& origin);
};


#endif //SDIZO_PROJ_DYNAMICARRAY_HPP
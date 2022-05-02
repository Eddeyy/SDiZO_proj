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
protected:
    T* arr = nullptr;
public:

    DynamicArray();
    DynamicArray(const std::vector<T>& vec);
    virtual ~DynamicArray();

    void push_back(T val) override;
    void push_front(T val) override;
    void add(T val, size_t index) override;
    void pop_back() override;
    void pop_front() override;
    void erase(size_t index) override;
    void clear() override;

    ArrayElement<T> * find(const T& key) override;
    const Element<T> *rfind(const T& key) override;

    void print() override;

    const T& operator[] (const size_t index) const;
    ArrayElement<T>& operator[] (const size_t index);

    T getFirst() override;
    T getLast() override;

    DynamicArray(const DynamicArray& origin);
    DynamicArray& operator= (const DynamicArray& origin);
    DynamicArray& operator= (const std::vector<T> &array) override;
};


#endif //SDIZO_PROJ_DYNAMICARRAY_HPP

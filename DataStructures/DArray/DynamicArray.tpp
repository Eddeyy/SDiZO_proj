#ifndef SDIZO_PROJ_DYNAMIC_ARRAY_TPP
#define SDIZO_PROJ_DYNAMIC_ARRAY_TPP
#include "DynamicArray.hpp"

template<typename T>
DynamicArray<T>::DynamicArray() : DataStruct<T>()
{
    this->arr = new T[0];
}

template<typename T>
DynamicArray<T>::~DynamicArray()
{
    delete[] this->arr;
}

template<typename T>
void DynamicArray<T>::push_back(T val)
{
    this->num_of_elements++;
    T *temp = new T[this->num_of_elements];

    for (int i = 0; i < this->num_of_elements - 1; i++)
    {
        temp[i] = this->arr[i];
    }
    temp[this->num_of_elements - 1] = val;

    delete[] this->arr;

    this->arr = temp;
}


template<typename T>
void DynamicArray<T>::push_front(T val)
{
    this->num_of_elements++;
    T *temp = new T[this->num_of_elements];

    temp[0] = val;

    for (int i = 0; i < this->num_of_elements - 1; i++)
    {
        temp[i + 1] = this->arr[i];
    }

    delete[] this->arr;

    this->arr = temp;
}

template<typename T>
void DynamicArray<T>::put(T val, size_t index)
{
    if (index < 0 || index > this->num_of_elements)
        throw std::out_of_range("Index out of range!");

    this->num_of_elements++;
    T *temp = new T[this->num_of_elements];

    for (int i = 0; i < index; i++)
    {
        temp[i] = this->arr[i];
    }

    temp[index] = val;

    for (int i = index + 1; i < this->num_of_elements; i++)
    {
        temp[i] = this->arr[i - 1];
    }

    delete[] this->arr;

    this->arr = temp;
}

template<typename T>
void DynamicArray<T>::pop_back()
{
    this->num_of_elements--;
    T *temp = new T[this->num_of_elements];

    for (int i = 0; i < this->num_of_elements; i++)
    {
        temp[i] = this->arr[i];
    }
    delete[] this->arr;

    this->arr = temp;
}

template<typename T>
void DynamicArray<T>::pop_front()
{
    T *temp = new T[this->num_of_elements - 1];

    for (int i = 1; i < this->num_of_elements; i++)
    {
        temp[i - 1] = this->arr[i];
    }
    delete[] this->arr;

    this->num_of_elements--;

    this->arr = temp;
}

template<typename T>
void DynamicArray<T>::erase(size_t index)
{
    if (index < 0 || index >= this->num_of_elements)
        throw std::out_of_range("Index out of range!");

    T *temp = new T[this->num_of_elements - 1];

    for (int i = 0; i < index; i++)
    {
        temp[i] = this->arr[i];
    }

    for (int i = index; i < this->num_of_elements - 1; i++)
    {
        temp[i] = this->arr[i + 1];
    }

    delete[] this->arr;
    this->num_of_elements--;

    this->arr = temp;
}

template<typename T>
T &DynamicArray<T>::operator[](const int index)
{
    if (index < 0 || index >= this->num_of_elements)
        throw std::out_of_range("Index out of range!");

    return this->arr[index];
}

template<typename T>
DynamicArray<T>::DynamicArray(const DynamicArray &origin)
{
    this->num_of_elements = origin.num_of_elements;

    if (this->arr != nullptr)
        delete[] this->arr;

    this->arr = new T[this->num_of_elements];

    for (int i = 0; i < this->num_of_elements; i++)
    {
        this->arr[i] = origin.arr[i];
    }
}

template<typename T>
DynamicArray<T> &DynamicArray<T>::operator=(const DynamicArray &origin)
{
    if(this == &origin)
        return *this;

    this->num_of_elements = origin.num_of_elements;

    if (this->arr != nullptr)
        delete[] this->arr;

    this->arr = new T[this->num_of_elements];

    for (int i = 0; i < this->num_of_elements; i++)
    {
        this->arr[i] = origin.arr[i];
    }

    return *this;
}

#endif
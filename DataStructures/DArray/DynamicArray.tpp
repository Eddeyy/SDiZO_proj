#ifndef SDIZO_PROJ_DYNAMIC_ARRAY_TPP
#define SDIZO_PROJ_DYNAMIC_ARRAY_TPP
#include "DynamicArray.hpp"

template<typename T>
DynamicArray<T>::DynamicArray() : DataStruct<T>("Dynamic Array")
{
    this->arr = new T[0];
}

template<typename T>
DynamicArray<T>::DynamicArray(const std::vector<T> &vec)
{
    *this = vec;
}

template<typename T>
DynamicArray<T>::~DynamicArray()
{
    delete[] this->arr;
    std::cout << "DArr memory freed\n";
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
void DynamicArray<T>::add(T val, size_t index)
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

    for (size_t i = index + 1; i < this->num_of_elements; i++)
    {
        temp[i] = this->arr[i - 1];
    }

    delete[] this->arr;

    this->arr = temp;
}

template<typename T>
void DynamicArray<T>::pop_back()
{
    if(this->num_of_elements>0)
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

    for (size_t i = index; i < this->num_of_elements - 1; i++)
    {
        temp[i] = this->arr[i + 1];
    }

    delete[] this->arr;
    this->num_of_elements--;

    this->arr = temp;
}

template <typename T>
void DynamicArray<T>::clear()
{
    delete[] this->arr;
    this->num_of_elements = 0;
    this->arr = nullptr;
}

template <typename T>
void DynamicArray<T>::print()
{
    std::cout << "Elements in Array:\n";
    std::string result = "[ ";
    for(int i = 0; i <this->num_of_elements; i++)
    {
        result += std::to_string(this->arr[i]);
        if(i!=this->num_of_elements-1)
            result += ",\n";
    }
    result += " ]\n";
    std::cout << result;
}

template<typename T>
const T &DynamicArray<T>::operator[](const int index) const
{
    if (index < 0 || index >= this->num_of_elements)
        throw std::out_of_range("Index out of range!");

    return this->arr[index];
}

template<typename T>
ArrayElement<T>& DynamicArray<T>::operator[](const int index)
{
    ArrayElement<T> temp;
    if (index < 0 || index >= this->num_of_elements)
        throw std::out_of_range("Index out of range!");

    temp.setVal(this->arr[index]);
    return temp;
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


template<typename T>
DynamicArray<T> &DynamicArray<T>::operator= (const std::vector<T> &array)
{
    if(this->num_of_elements == array.size())
    {
        bool isDifferent = false;
        for (int i = 0; i < this->num_of_elements; i++)
            if (this->arr[i] != array[i])
            {
                isDifferent = true;
                break;
            }
        if (!isDifferent)
            return *this;
    }

    this->num_of_elements = array.size();

    if (this->arr != nullptr)
        delete[] this->arr;

    this->arr = new T[this->num_of_elements];

    for (int i = 0; i < this->num_of_elements; i++)
    {
        this->arr[i] = array[i];
    }

    return *this;
}

template<typename T>
const Element<T> *DynamicArray<T>::find(const T &key)
{
    ArrayElement<T> *temp;
    for(int i = 0; i < this->num_of_elements; i++)
        if(this->arr[i]==key)
        {
            temp->setVal(this->arr[i]);
            return temp;
        }
    throw std::invalid_argument("No such key in array.");
}

template<typename T>
const Element<T> *DynamicArray<T>::rfind(const T &key)
{
    ArrayElement<T> *temp;
    for(int i = this->num_of_elements-1; i>-1; i--)
        if(this->arr[i]==key)
        {
            temp->setVal(this->arr[i]);
            return temp;
        }

    throw std::invalid_argument("No such key in array.");
}

#endif
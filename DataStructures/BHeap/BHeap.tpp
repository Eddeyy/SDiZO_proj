//
// Created by thero on 18.04.2022.
//

#include "BHeap.hpp"

template<typename T>
BHeap<T>::BHeap()
:DataStruct<T>("Binary Max Heap"), root{nullptr}
{

}
template<typename T>
void BHeap<T>::push_back(T val)
{
    add(val);
}

template<typename T>
void BHeap<T>::pop_back()
{
    erase(this->num_of_elements-1);
}

template<typename T>
void BHeap<T>::push_front(T val)
{
    add(val);
}

template<typename T>
void BHeap<T>::pop_front()
{
    erase(0);
}

template<typename T>
void BHeap<T>::add(T val, size_t index)
{
    this->num_of_elements++;
    T *temp = new T[this->num_of_elements];

    for (int i = 0; i < this->num_of_elements - 1; i++)
    {
        temp[i] = this->root[i];
    }
    temp[this->num_of_elements - 1] = val;

    delete[] this->root;

    this->root = temp;

    int i = this->num_of_elements-1;

    restoreHeap();
}

template<typename T>
void BHeap<T>::erase(size_t index)
{
    if(index > -1 && index < this->num_of_elements-1)
    {
        if(std::is_integral<T>::value)
            root[index] = INT_MAX;
        else
            throw ut::utilityException("Erase not implemented correctly for that type in BHeap.tpp");

        while (index != 0 && root[parent(index)]>root[index])
        {
            swap(index, parent(index));
            index = parent(index);
        }
        extractMax();
    }
    throw std::out_of_range("Index out of range!\n");
}

template<typename T>
void BHeap<T>::extractMax()
{
    T* temp = new T[this->num_of_elements-1];

    if(this->num_of_elements>1)
    {
        T root_val = root[0];
        root[0] = root[this->num_of_elements-1];
        this->num_of_elements--;
        heapifyMax(0);
    }
    else if(this->num_of_elements==1)
        this->num_of_elements--;
    else
        throw std::invalid_argument("Heap is empty!\n");

    for(int i = 0; i < this->num_of_elements; i++)
    {
        temp[i] = root[i];
    }

    delete[] root;

    root = temp;
}

template<typename T>
void BHeap<T>::clear()
{
    delete[] this->root;
    this->num_of_elements = 0;
    this->root = nullptr;
}

template<typename T>
void BHeap<T>::print()
{
//TODO: ukradzione, dieki gniotek

    if (this->num_of_elements > 0 && this->root != nullptr)
    {
        bool outOfBound = false;
        size_t first = 0;
        size_t last = 1;

        // Calculate the maximum number of nodes at the current heap level
        size_t space = pow(2, floor(log2(this->num_of_elements)) + 1) - 1;

        while (!outOfBound)
        {
            // Print space before each heap level
            std::cout << std::string(space / 2 * 3, ' ');

            // Print nodes on current heap level
            for (size_t i = first; i < last; i++)
            {
                if (i >= this->num_of_elements)
                {
                    outOfBound = true;
                    break;
                }
                std::cout << '[' << this->root[i] << ']' << std::string(space * 3, ' ');
            }
            std::cout << "\n\n";

            // Change indexes or last and first node on each heap level
            first = last;
            last = 2 * last + 1;

            // Change size of space between nodes
            space = space / 2;
        }
        return;
    }
    std::cout << "Data structure is empty" << std::endl;
}

template<typename T>
void BHeap<T>::heapifyMax(const size_t& index)
{
    size_t left_ = left(index);
    size_t right_ = right(index);
    size_t max;

    if(left_ <= this->num_of_elements-1 && root[left_]>root[index])
        max = left_;
    else
        max = index;

    if(right_ <= this->num_of_elements-1 && root[right_]>root[max])
        max = right_;

    if(max != index)
    {
        swap(index, max);
        heapifyMax(max);
    }
}

template<typename T>
void BHeap<T>::swap(const T *a, const T *b)
{
    T a_val = *a;
    *a = *b;
    *b = a_val;
}

template<typename T>
void BHeap<T>::swap(const size_t& a_index,const size_t& b_index)
{
    T a_val = root[a_index];
    root[a_index]=root[b_index];
    root[b_index]=a_val;
}

template<typename T>
const T *BHeap<T>::kfind(const T &key)
{
    return nullptr;
}


template<typename T>
const T *BHeap<T>::krfind(const T &key)
{
    return nullptr;
}

template<typename T>
const T &BHeap<T>::operator[](int index) const
{
    if(root == nullptr)
        throw std::invalid_argument("The heap appears to be empty!\n");
    if(index > -1 && index < this->num_of_elements)
    {
        return root[index];
    }
    throw std::out_of_range("Index out of range!\n");
}

template<typename T>
BHeap<T>& BHeap<T>::operator=(const BHeap &origin)
{
    if(this == &origin)
        return *this;

    this->num_of_elements = origin.num_of_elements;

    if (this->root != nullptr)
        delete[] this->root;

    this->root = new T[this->num_of_elements];

    for (int i = 0; i < this->num_of_elements; i++)
    {
        this->root[i] = origin.root[i];
    }

    return *this;
}

template<typename T>
BHeap<T>& BHeap<T>::operator=(const std::vector<T> &origin)
{

    if(this->num_of_elements == origin.size())
    {
        bool isDifferent = false;
        for (int i = 0; i < this->num_of_elements; i++)
            if (this->root[i] != origin[i])
            {
                isDifferent = true;
                break;
            }
        if (!isDifferent)
            return *this;
    }

    this->num_of_elements = origin.size();

    if (this->root != nullptr)
        delete[] this->root;

    this->root = new T[this->num_of_elements];

    for (int i = 0; i < this->num_of_elements; i++)
    {
        this->root[i] = origin[i];
    }
    buildHeap();
    return *this;
}

template<typename T>
size_t BHeap<T>::parent(size_t index)
{
    return (index-1)/2;
}

template<typename T>
size_t BHeap<T>::left(size_t index)
{
    return (2*index +1);
}

template<typename T>
size_t BHeap<T>::right(size_t index)
{
    return (2*index + 2);
}

template<typename T>
const Element<T>* BHeap<T>::find(const T &key)
{
    //TODO: implement to gowno
    return nullptr;
}

template<typename T>
const Element<T>* BHeap<T>::rfind(const T &key)
{
    //TODO: implement to gowno
    return nullptr;
}

template<typename T>
void BHeap<T>::restoreHeap()
{
    int i = this->num_of_elements-1;

    while (i != 0 && root[parent(i)] < root[i])
    {
        swap(i, parent(i));
        i = parent(i);
    }
}

template<typename T>
void BHeap<T>::buildHeap()
{
    for(int i = (this->num_of_elements-1)/2; i > -1; i--)
        heapifyMax(i);
}

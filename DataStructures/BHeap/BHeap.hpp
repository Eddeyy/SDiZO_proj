//
// Created by thero on 18.04.2022.
//

#ifndef SDIZO_PROJ_BHEAP_HPP
#define SDIZO_PROJ_BHEAP_HPP
#include "../DataStruct.hpp"
#include "../../Utility/Utilities.hpp"

template<typename T>
class BHeap : public DataStruct<T>
{
protected:
    void swap(const size_t& a_index, const size_t& b_index);
    void swap(const T* a, const T* b);

    T* root;
public:

    BHeap();
    void push_back(T val) override;
    void pop_back() override;
    void push_front(T val) override;
    void pop_front() override;
    void add(T val, size_t index = -1) override;
    void erase (size_t index) override;

    void clear() override;

    void print() override;
    void heapifyMax(const size_t& index);
    void extractMax();
    void restoreHeap();
    void buildHeap();

    size_t parent(size_t index);
    size_t left(size_t index);
    size_t right(size_t index);


    const Element<T>* find(const T& key) override;
    const Element<T>* rfind(const T& key) override;
    const T* kfind(const T& key) ;
    const T* krfind(const T& key) ;

    const T& operator[] (int index) const override;
    BHeap& operator= (const BHeap& origin);
    BHeap& operator= (const std::vector<T>& origin) override;

};


#endif //SDIZO_PROJ_BHEAP_HPP

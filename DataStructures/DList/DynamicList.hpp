//
// Created by thero on 09.03.2022.
//

#ifndef SDIZO_PROJ_DYNAMICLIST_HPP
#define SDIZO_PROJ_DYNAMICLIST_HPP
#include "../DataStruct.hpp"
#include "ListElement.hpp"
#include "ListElement.tpp"

template<typename T>
class DynamicList : public DataStruct<T>
{
protected:
    ListElement<T>* head;
    ListElement<T>* tail;

public:
    DynamicList();
    ~DynamicList();

    void push_back(T val) override;
    void push_front(T val) override;
    void put(T val, size_t index) override;
    void pop_back() override;
    void pop_front() override;
    void erase(size_t index) override;
    void print() override;

    const T& operator[] (int index) const;
    ListElement<T>& operator[] (int index);

    DynamicList(const DynamicList& origin);
    DynamicList& operator= (const DynamicList& origin);

};
#endif //SDIZO_PROJ_DYNAMICLIST_HPP

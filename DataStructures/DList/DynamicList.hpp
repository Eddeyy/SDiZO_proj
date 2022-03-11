//
// Created by thero on 09.03.2022.
//

#ifndef SDIZO_PROJ_DYNAMICLIST_HPP
#define SDIZO_PROJ_DYNAMICLIST_HPP
#include "../DataStruct.hpp"
#include "ListElement.hpp"

template<typename T>
class DynamicList : public DataStruct<T>
{
protected:
    ListElement<T>* first;
    ListElement<T>* last;

public:
    DynamicList();
    ~DynamicList();

    void push_back(T val) override;
    void push_front(T val) override;
    //TODO implement overrides below in the .tpp file
    void put(T val, int index) override {};
    void pop_back() override {};
    void pop_front() override {};
    void erase(int index) override {};
    void print() override;

    T& operator[] (int index);

    DynamicList(const DynamicList& origin);
    DynamicList& operator= (const DynamicList& origin);
};
#endif //SDIZO_PROJ_DYNAMICLIST_HPP

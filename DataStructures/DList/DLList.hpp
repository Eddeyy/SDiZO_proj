//
// Created by thero on 09.03.2022.
//

#ifndef SDIZO_PROJ_DLLIST_HPP
#define SDIZO_PROJ_DLLIST_HPP
#include "../DataStruct.hpp"
#include "ListElement.hpp"
#include "ListElement.tpp"

template<typename T>
class DLList : public DataStruct<T>
{
protected:
    ListElement<T>* head;
    ListElement<T>* tail;

public:
    DLList();
    DLList(const std::vector<T>& vec);
    virtual ~DLList();

    void push_back(T val) override;
    void push_front(T val) override;
    void add(T val, size_t index) override;
    void pop_back() override;
    void pop_front() override;
    void erase(size_t index) override;
    void print() override;
    void clear() override;

    const Element<T> *find(const T& key) override;
    const Element<T> *rfind(const T& key) override;

    const T& operator[] (const size_t index) const;
    ListElement<T>& operator[] (const size_t index);

    DLList(const DLList& origin);
    DLList& operator= (const DLList& origin);
    DLList& operator= (const std::vector<T> &array) override;

};
#endif //SDIZO_PROJ_DLLIST_HPP

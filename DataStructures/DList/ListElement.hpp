//
// Created by thero on 09.03.2022.
//

#ifndef SDIZO_PROJ_LISTELEMENT_HPP
#define SDIZO_PROJ_LISTELEMENT_HPP
#include "DynamicList.hpp"

template<typename T>
class ListElement
{
public:
    ListElement() = delete;
    ListElement(T val, ListElement* prev, ListElement* next);
protected:
    T value;

    ListElement* nextElement;
    ListElement* prevElement;

    void setPrev(ListElement* const prev);
    void setNext(ListElement* const next);
    void setVal(const T& val);

    const T& getValue();
    ListElement* const getNext() const;
    ListElement* const getPrev() const;

    ListElement& operator= (const ListElement& origin);

    bool operator== (const ListElement& B){return this->value == B.value;};
    bool operator!= (const ListElement& B){return *this != B;};
    bool operator< (const ListElement& B){return this->value < B.value;};
    bool operator> (const ListElement& B){return B < *this;};
    bool operator<= (const ListElement& B){return !(*this > B);};
    bool operator>= (const ListElement& B){return !(*this < B);};

    template<typename TT>
    friend class DynamicList;
};


#endif //SDIZO_PROJ_LISTELEMENT_HPP

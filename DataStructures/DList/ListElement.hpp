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

    ListElement& operator= (const ListElement& origin);
    ListElement& operator= (T val);

    bool operator== (const ListElement& B){return this->value == B.value;};
    bool operator!= (const ListElement& B){return *this != B;};
    bool operator< (const ListElement& B){return this->value < B.value;};
    bool operator> (const ListElement& B){return B < *this;};
    bool operator<= (const ListElement& B){return !(*this > B);};
    bool operator>= (const ListElement& B){return !(*this < B);};

    std::ostream& operator<<(std::ostream &out);

    const T& getValue();

    void setPrev(ListElement* const prev);
    void setNext(ListElement* const next);
protected:
    T value;

    ListElement* nextElement;
    ListElement* prevElement;

    void setVal(const T& val);

    ListElement* const getNext() const;
    ListElement* const getPrev() const;

    template<typename TT>
    friend class DynamicList;
};


#endif //SDIZO_PROJ_LISTELEMENT_HPP

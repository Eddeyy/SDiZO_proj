//
// Created by thero on 09.03.2022.
//
#ifndef SDIZO_PROJ_LISTELEMENT_TPP
#define SDIZO_PROJ_LISTELEMENT_TPP
#include "ListElement.hpp"

template<typename T>
ListElement<T>::ListElement(T val, ListElement* prev, ListElement* next) :
nextElement{next}, prevElement{prev}
{
    this->value = val;
}

template<typename T>
void ListElement<T>::setPrev(ListElement<T>* const prev)
{
    this->prevElement = prev;
}

template<typename T>
void ListElement<T>::setNext(ListElement<T>* const next)
{
 this->nextElement = next;
}

template<typename T>
ListElement<T>* const ListElement<T>::getNext() const
{
    return this->nextElement;
}

template<typename T>
ListElement<T>* const ListElement<T>::getPrev() const
{
    return this->prevElement;
}

template<typename T>
ListElement<T> &ListElement<T>::operator=(const Element<T> &origin)
{
    if(this == &origin)
        return *this;

    this->value = origin.value;

    return *this;
}

template<typename T>
ListElement<T> &ListElement<T>::operator=(T val)
{
    if(this->getVal() == val)
        return *this;

    this->value = val;

    return *this;
}

template<typename T>
std::ostream& ListElement<T>::operator<<(std::ostream &out)
{
    out << this->getVal();
    return out;
}

#endif

//TODO: comment the code
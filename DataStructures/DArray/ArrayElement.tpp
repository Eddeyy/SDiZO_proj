//
// Created by thero on 15.04.2022.
//

#include "ArrayElement.hpp"


template<typename T>
ArrayElement<T>::ArrayElement()
{

}

template<typename T>
ArrayElement<T>::ArrayElement(T val)
{

}

template<typename T>
ArrayElement<T> &ArrayElement<T>::operator=(const Element<T> &origin)
{
    if(this == &origin)
        return *this;

    this->value = origin.value;

    return *this;
}

template<typename T>
ArrayElement<T> &ArrayElement<T>::operator=(T val)
{
    if(this->getValue() == val)
        return *this;

    this->value = val;

    return *this;
}

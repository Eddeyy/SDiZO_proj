//
// Created by thero on 15.04.2022.
//

#ifndef SDIZO_PROJ_ARRAYELEMENT_HPP
#define SDIZO_PROJ_ARRAYELEMENT_HPP
#include <iostream>
#include "../Element.hpp"

template<typename T>
class ArrayElement : public Element<T>
{
public:
    ArrayElement();
protected:
    explicit ArrayElement(T val);

    ArrayElement<T>& operator= (const Element<T>& origin) override;
    ArrayElement<T>& operator= (T val) override;

};



#endif //SDIZO_PROJ_ARRAYELEMENT_HPP

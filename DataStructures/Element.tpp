//
// Created by thero on 02.05.2022.
//

#ifndef SDIZO_PROJ_ELEMENT_TPP
#define SDIZO_PROJ_ELEMENT_TPP

#include "Element.hpp"

template<typename T>
void Element<T>::print()
{
    std::cout << "Found element with value of : " << this->getVal() << "\nAt : " << this << std::endl;
}

#endif //SDIZO_PROJ_ELEMENT_TPP

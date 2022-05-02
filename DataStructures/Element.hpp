//
// Created by thero on 15.04.2022.
//

#ifndef SDIZO_PROJ_ELEMENT_HPP
#define SDIZO_PROJ_ELEMENT_HPP
#include <iostream>

template<typename T>
class Element
{
public:
    Element() = default;

    virtual Element& operator= (const Element& origin) = 0;
    virtual Element& operator= (T val) = 0;

    bool operator== (const Element& B){return this->value == B.value;};
    bool operator!= (const Element& B){return *this != B;};
    bool operator< (const Element& B){return this->value < B.value;};
    bool operator> (const Element& B){return B < *this;};
    bool operator<= (const Element& B){return !(*this > B);};
    bool operator>= (const Element& B){return !(*this < B);};

    bool operator== (const T& B){return this->value == B;};
    bool operator!= (const T& B){return this->value != B;};
    bool operator< (const T& B){return this->value < B;};
    bool operator> (const T& B){return B < *this;};
    bool operator<= (const T& B){return !(*this > B);};
    bool operator>= (const T& B){return !(*this < B);};

    virtual std::ostream& operator<<(std::ostream &out)
    {
        out << this->getVal();
        return out;
    };

    T& getVal()
    {
        return this->value;
    };

    virtual void print();

    T value;

    void setVal(const T& val)
    {
        value = val;
    };
};



#endif //SDIZO_PROJ_ELEMENT_TPP

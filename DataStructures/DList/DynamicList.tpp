#ifndef SDIZO_PROJ_DYNAMICLIST_TPP
#define SDIZO_PROJ_DYNAMICLIST_TPP
#include "DynamicList.hpp"

template<typename T>
DynamicList<T>::DynamicList()
: DataStruct<T>(), first{nullptr}, last{nullptr}
{

}

template<typename T>
DynamicList<T>::~DynamicList()
{
    if(last!=nullptr)
    {
        ListElement<T>* cur = last;
        ListElement<T>* prev = last;

        for(int i = this->num_of_elements; i > 0; i--)
        {
            if(i>1)
                cur = cur->getPrev();
            delete prev;
            prev = cur;
        }
    }
}

template<typename T>
void DynamicList<T>::push_back(T val)
{
    auto newElement = new ListElement<T>(val, last, nullptr);

    if(this->first == nullptr)
    {
        this->first = newElement;
        this->last = newElement;
    }
    else
        this->last->setNext(newElement);
    this->last = newElement;

    this->num_of_elements++;
}

template<typename T>
void DynamicList<T>::push_front(T val)
{

    auto newElement = new ListElement<T>(val, nullptr, first);

    if(this->first == nullptr)
    {
        this->first = newElement;
        this->last = newElement;
    }
    else
        this->first->setPrev(newElement);
    this->first = newElement;

    this->num_of_elements++;
}

template<typename T>
void DynamicList<T>::print()
{
    ListElement<T>* curEl = first;

    std::cout << "Elementy w Liscie:\n";
    while(curEl!=nullptr)
    {
        std::cout << curEl->getValue() << std::endl;
        curEl = curEl->getNext();
    }
}


#endif
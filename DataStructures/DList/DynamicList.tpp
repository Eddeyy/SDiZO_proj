#ifndef SDIZO_PROJ_DYNAMICLIST_TPP
#define SDIZO_PROJ_DYNAMICLIST_TPP
#include "DynamicList.hpp"

template<typename T>
DynamicList<T>::DynamicList()
: DataStruct<T>(), head{nullptr}, tail{nullptr}
{
    //constructor body
}

template<typename T>
DynamicList<T>::~DynamicList()
{
    if(tail != nullptr)
    {
        ListElement<T>* cur = tail;
        ListElement<T>* prev = tail;

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
    auto newElement = new ListElement<T>(val, tail, nullptr);

    if(this->head == nullptr)
    {
        this->head = newElement;
        this->tail = newElement;
    }
    else
        this->tail->setNext(newElement);
    this->tail = newElement;

    this->num_of_elements++;
}

template<typename T>
void DynamicList<T>::push_front(T val)
{
    auto newElement = new ListElement<T>(val, nullptr, head);

    if(this->head == nullptr)
    {
        this->head = newElement;
        this->tail = newElement;
    }
    else
        this->head->setPrev(newElement);
    this->head = newElement;

    this->num_of_elements++;
}

template<typename T>
void DynamicList<T>::put(T val, size_t index)
{
    if (index < 0 || index > this->num_of_elements+1)
        throw std::out_of_range("Index out of range!");

    if(index == 0)
    {
        auto prevHead = head;
        this->head = new ListElement<T>(val, nullptr , this->head);
        prevHead->setPrev(this->head);
    }
    else if(index == this->num_of_elements)
    {
        auto prevTail = tail;
        this->tail = new ListElement<T>(val, tail, nullptr);
        prevTail->setNext(this->tail);
    }
    else
    {
        auto prev = &(*this)[index-1], next = &(*this)[index];

        prev->setNext(new ListElement<T>(val, prev, next));
        next->setPrev(prev->getNext());
    }
    this->num_of_elements++;
}

template<typename T>
void DynamicList<T>::pop_back()
{
    auto prev = (*this)[this->num_of_elements-1];
    prev.setNext(nullptr);
    delete tail;
    tail = &prev;
    this->num_of_elements--;
}

template<typename T>
void DynamicList<T>::pop_front()
{
    auto prev = (*this)[1];
    prev.setPrev(nullptr);
    delete head;
    head = &prev;
    this->num_of_elements--;
}

template<typename T>
void DynamicList<T>::erase(size_t index)
{
    auto prev = (*this)[index].getPrev();
    auto next = (*this)[index].getNext();

    delete &(*this)[index];

    if(prev!=nullptr)
        prev->setNext(next);
    else
        head = next;

    if(next!=nullptr)
        next->setPrev(prev);
    else
        tail = prev;

    this->num_of_elements--;
}

template<typename T>
void DynamicList<T>::print()
{
    ListElement<T>* curEl = head;

    std::cout << "Elementy w Liscie:\n";
    while(curEl!=nullptr)
    {
        std::cout << curEl->getValue() << std::endl;
        curEl = curEl->getNext();
    }
}

template<typename T>
const T &DynamicList<T>::operator[](int index) const
{
    ListElement<T>* elem;
    if(head == nullptr)
    {
        throw std::invalid_argument("The list appears to be empty!");
    }

    if (index < 0 || index >= this->num_of_elements)
        throw std::out_of_range("Index out of range!");

    if(index < (this->num_of_elements-1)/2)
    {
        elem = head;
        for (int i = 0; i < index; i++)
        {
            elem = elem->getNext();
        }
    }
    else
    {
        elem = tail;
        for (int i = this->num_of_elements-1; i > index; i--)
        {
            elem = elem->getPrev();
        }
    }
        return elem->getValue();
}

template<typename T>
ListElement<T> &DynamicList<T>::operator[](int index)
{
    ListElement<T>* elem;
    if(head == nullptr)
        throw std::invalid_argument("The list appears to be empty!");

    if (index < 0 || index >= this->num_of_elements)
        throw std::out_of_range("Index out of range!");

    if(index < (this->num_of_elements-1)/2)
    {
        elem = head;
        for (int i = 0; i != index; i++)
        {
            elem = elem->getNext();
        }
    }
    else
    {
        elem = tail;
        for (int i = this->num_of_elements-1; i != index; i--)
        {
            elem = elem->getPrev();
        }
    }

    return *elem;
}

template<typename T>
DynamicList<T>::DynamicList(const DynamicList<T> &origin)
        : DynamicList()
{
    for(int i = 0; i < origin.num_of_elements; i++)
    {
        this->push_back(origin[i]);
    }
}

template<typename T>
DynamicList<T> &DynamicList<T>::operator=(const DynamicList &origin)
{
    if(this == &origin)
        return *this;

    for(int i = 0; i < origin.num_of_elements; i++)
    {
        this->push_back(origin[i]);
    }
    return *this;
}


#endif

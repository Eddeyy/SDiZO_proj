#ifndef SDIZO_PROJ_DLLIST_TPP
#define SDIZO_PROJ_DLLIST_TPP
#include "DLList.hpp"

template<typename T>
DLList<T>::DLList()
: DataStruct<T>(), head{nullptr}, tail{nullptr}
{
    //constructor body
}

template<typename T>
DLList<T>::~DLList()
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
    std::cout << "DList memory freed\n";
}

template<typename T>
void DLList<T>::push_back(T val)
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
void DLList<T>::push_front(T val)
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
void DLList<T>::add(T val, size_t index)
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
void DLList<T>::pop_back()
{
    auto prev = (*this)[this->num_of_elements-1];
    prev.setNext(nullptr);
    delete tail;
    tail = &prev;
    this->num_of_elements--;
}

template<typename T>
void DLList<T>::pop_front()
{
    auto prev = (*this)[1];
    prev.setPrev(nullptr);
    delete head;
    head = &prev;
    this->num_of_elements--;
}

template<typename T>
void DLList<T>::erase(size_t index)
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
void DLList<T>::print()
{
    ListElement<T>* curEl = head;
    std::string result = "[ ";

    std::cout << "Elements in List:\n";
    while(curEl!=nullptr)
    {
        result += std::to_string(curEl->getValue());
        if(curEl->getNext()!=nullptr)
            result += ", ";
        curEl = curEl->getNext();
    }
    result += " ]\n";
    std::cout << result;
}

template<typename T>
const T &DLList<T>::operator[](int index) const
{
    ListElement<T>* elem;
    if(head == nullptr)
    {
        throw std::invalid_argument("The list appears to be empty!");
    }

    if (index < 0 || index >= this->num_of_elements)
        throw std::out_of_range("Index out of range!");

    if(index < (this->num_of_elements)/2)
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
ListElement<T> &DLList<T>::operator[](int index)
{
    ListElement<T>* elem;
    if(head == nullptr)
        throw std::invalid_argument("The list appears to be empty!");

    if (index < 0 || index >= this->num_of_elements)
        throw std::out_of_range("Index out of range!");

    if(index < (this->num_of_elements)/2)
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
DLList<T>::DLList(const DLList<T> &origin)
        : DLList()
{
    for(int i = 0; i < origin.num_of_elements; i++)
    {
        this->push_back(origin[i]);
    }
}

template<typename T>
DLList<T> &DLList<T>::operator=(const DLList &origin)
{
    if(this == &origin)
        return *this;

    for(int i = 0; i < origin.num_of_elements; i++)
    {
        this->push_back(origin[i]);
    }
    return *this;
}

template<typename T>
const Element<T>* DLList<T>::find(const T& key)
{
    ListElement<T>* temp = this->head;
    for(int i = 0; i<this->num_of_elements; i++)
    {
        if(temp->getValue() == key)
        {
            return temp;
        }
        temp = temp->getNext();
    }
    throw std::invalid_argument("No such key in list.");
}
template<typename T>
const Element<T>* DLList<T>::rfind(const T& key)
{
    ListElement<T>* temp = this->tail;
    for(int i = this->num_of_elements-1; i>0; i--)
    {
        if(temp->getValue() == key)
        {
            return temp;
        }
        temp = temp->getPrev();
    }
    throw std::invalid_argument("No such key in list.");
}


#endif
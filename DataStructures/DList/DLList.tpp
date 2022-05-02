#ifndef SDIZO_PROJ_DLLIST_TPP
#define SDIZO_PROJ_DLLIST_TPP
#include "DLList.hpp"

template<typename T>
DLList<T>::DLList()
: DataStruct<T>("Doubly-linked List"), head{nullptr}, tail{nullptr}
{
    //constructor body
}

template<typename T>
DLList<T>::DLList(const std::vector<T> &vec)
: DLList<T>()
{
    *this = vec;
}

template<typename T>
DLList<T>::~DLList()
{
    clear();
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
    if (index > this->num_of_elements)
        throw std::out_of_range("Index out of range!");

    if(index == 0)
    {
        auto prevHead = head;
        this->head = new ListElement<T>(val, nullptr , this->head);

        if(this->num_of_elements)
            prevHead->setPrev(this->head);
        else
            this->tail = head;
    }
    else if(index == this->num_of_elements)
    {
        auto prevTail = tail;
        this->tail = new ListElement<T>(val, tail, nullptr);

        if(this->num_of_elements)
            prevTail->setNext(this->tail);
        else
            this->head = tail;
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
    if(!this->num_of_elements)
    {
        throw std::invalid_argument("The list appears to be empty!");
    }

    if(this->num_of_elements>1)
    {
        auto prev = tail->getPrev();
        prev->setNext(nullptr);
        delete tail;
        tail = prev;
    }
    else
    {
        delete tail;
        tail=nullptr;
        head=nullptr;
    }

    this->num_of_elements--;
}

template<typename T>
void DLList<T>::pop_front()
{
    if(!this->num_of_elements)
    {
        throw std::invalid_argument("The list appears to be empty!");
    }
    if(this->num_of_elements>1)
    {
        auto prev = head->getNext();
        prev->setPrev(nullptr);
        delete head;
        head = prev;
    }
    else
    {
        delete head;
        head = nullptr;
        tail = nullptr;
    }

    this->num_of_elements--;
}

template<typename T>
void DLList<T>::erase(size_t index)
{
    if(!this->num_of_elements)
    {
        throw std::invalid_argument("The list appears to be empty!");
    }

    auto prev = (*this)[index].getPrev();
    auto next = (*this)[index].getNext();

    delete &(*this)[index];

    if(prev)
        prev->setNext(next);
    else
        head = next;

    if(next)
        next->setPrev(prev);
    else
        tail = prev;

    this->num_of_elements--;
}

template<typename T>
void DLList<T>::clear()
{
    for(int i = this->num_of_elements-1; i>0; i--)
    {
        auto prev = tail->getPrev();
        prev->setNext(nullptr);
        delete tail;
        tail = prev;
    }
    delete tail;
    tail = nullptr;
    head = nullptr;

    this->num_of_elements = 0;
}

template<typename T>
void DLList<T>::print()
{
    ListElement<T>* curEl = head;
    std::string result(50, '=');
    result.append(1,'\n');

    std::cout << "Elements in List:\n";
    while(curEl)
    {

        if(curEl->getPrev())
            result += "<" + std::to_string(curEl->getPrev()->getVal()) + ">";
        else
            result += "<NULL>";
        result += " <<-- <" + std::to_string(curEl->getVal()) + "> -->> ";
        if(curEl->getNext())
            result += "<" + std::to_string(curEl->getNext()->getVal()) + ">";
        else
            result +="<NULL>";
        if(curEl->getNext())
            result += ",\n";
        curEl = curEl->getNext();
    }
    result.append(1,'\n');
    result.append(50,'=');
    result += "\n\n";
    std::cout << result;
}

template<typename T>
const T &DLList<T>::operator[](const size_t index) const
{
    ListElement<T>* elem;
    if(this->num_of_elements)
    {
        throw std::invalid_argument("The list appears to be empty!");
    }

    if (index >= this->num_of_elements)
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
        return elem->getVal();
}

template<typename T>
ListElement<T> &DLList<T>::operator[](const size_t index)
{
    ListElement<T>* elem;

    if(!this->num_of_elements)
        throw std::invalid_argument("The list appears to be empty!");

    if (index >= this->num_of_elements)
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

    this->clear();

    for(int i = 0; i < origin.num_of_elements; i++)
    {
        this->push_back(origin[i]);
    }

    return *this;
}

template<typename T>
DLList<T> &DLList<T>::operator=(const std::vector<T> &array)
{

    if(this->num_of_elements == array.size())
    {
        bool isDifferent = false;
        for (int i = 0; i < this->num_of_elements; i++)
            if ((*this)[i] != array[i])
            {
                isDifferent = true;
                break;
            }
        if (!isDifferent)
            return *this;
    }

    this->clear();

    for(int i = 0; i < array.size(); i++)
    {
        this->push_back(array[i]);
    }
    return *this;
}
template<typename T>
ListElement<T> * DLList<T>::find(const T& key)
{
    ListElement<T>* temp = this->head;
    for(int i = 0; i<this->num_of_elements; i++)
    {
        if(temp->getVal() == key)
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
    for(int i = this->num_of_elements-1; i>-1; i--)
    {
        if(temp->getVal() == key)
        {
            auto a = std::make_shared<ListElement<T>>(*temp);

            return &(*a);
        }
        temp = temp->getPrev();
    }
    throw std::invalid_argument("No such key in list.");
}

template<typename T>
T DLList<T>::getFirst()
{
    return head->getVal();
}

template<typename T>
T DLList<T>::getLast()
{
    return tail->getVal();
}


#endif

//TODO: comment the code
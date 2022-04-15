//
// Created by thero on 09.03.2022.
//

#ifndef SDIZO_PROJ_LISTELEMENT_HPP
#define SDIZO_PROJ_LISTELEMENT_HPP
#include "DynamicList.hpp"
#include "../Element.hpp"

template<typename T>
class ListElement : public Element<T>
{
public:
    ListElement() = delete;
protected:
    ListElement(T val, ListElement* prev, ListElement* next);

    ListElement<T>& operator= (const Element<T>& origin) override;
    ListElement<T>& operator= (T val) override;

    std::ostream& operator<<(std::ostream &out) override;

    ListElement* nextElement;
    ListElement* prevElement;
    ListElement* const getNext() const;
    ListElement* const getPrev() const;
    void setPrev(ListElement* const prev);
    void setNext(ListElement* const next);

    template<typename TT>
    friend class DynamicList;
};


#endif //SDIZO_PROJ_LISTELEMENT_HPP

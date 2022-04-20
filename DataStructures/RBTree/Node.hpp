//
// Created by thero on 19.04.2022.
//

#ifndef SDIZO_PROJ_NODE_HPP
#define SDIZO_PROJ_NODE_HPP

template<typename T>
class Node : public Element<T>
{
public:
    Node* parent;
    Node* l_child;
    Node* r_child;

    bool is_red;

    Node(T val, Node* parent_, Node* left,
    Node* right, bool is_red_)
    : parent(parent_), l_child(left), r_child(right), is_red(is_red_)
    { this->value = val;};

    Node()
            : parent(nullptr), l_child(nullptr), r_child(nullptr), is_red(true)
    { this->value = -1;};

    Node& operator= (const Element<T>& origin) { return *this; };
    Node& operator= (T val) { return *this;};

};


#endif //SDIZO_PROJ_NODE_HPP

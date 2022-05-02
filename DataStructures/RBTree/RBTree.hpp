//
// Created by thero on 19.04.2022.
//

#ifndef SDIZO_PROJ_RBTREE_HPP
#define SDIZO_PROJ_RBTREE_HPP
#include <iostream>
#include "Node.hpp"


template<typename T>
class Tester;

template<typename T>
class RBTree : public DataStruct<T>
{
private:
    Node<T>* root;
    Node<T>* guard;
    Node<T>* successor(Node<T>* node);
    Node<T>* min(Node<T>* node);

    void lRot(Node<T>* node);
    void rRot(Node<T>* node);
    void delFix(Node<T>* node);
    void delNodes(Node<T>* node);
    void getDepth(Node<T>* node, size_t& max_depth, size_t cur_depth);
    void placeNodes(Node<T>* node, Node<T>** table,const size_t& index);

public:
    RBTree();
    ~RBTree();

    void add(T val, size_t index = -1) override;
    void erase(size_t key) override;

    Node<T>* find(const T& key);
    const Node<T>* find(const T& key, const Node<T>* node);
    const Node<T> * rfind(const T& key) {return find(key);};

    void print() override;

    void push_back(T val) { };
    void pop_back() { };
    void push_front(T val) { };
    void pop_front() { };

    void clear() override;

    T getFirst() override;
    T getLast() override;

    RBTree& operator= (const std::vector<T>&);


    friend class Tester<int>;
};


#endif //SDIZO_PROJ_RBTREE_HPP

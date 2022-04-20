//
// Created by thero on 19.04.2022.
//
#ifndef SDIZO_PROJ_RBTREE_TPP
#define SDIZO_PROJ_RBTREE_TPP
#include <cmath>
#include <Windows.h>
#include "RBTree.hpp"

template<typename T>
RBTree<T>::RBTree()
: DataStruct<T>("Red-black Tree")
{
    this->guard = new Node<T>();
    this->guard->is_red = false;
    this->guard->parent = this->guard;
    this->guard->l_child = this->guard;
    this->guard->r_child = this->guard;

    this->root = this->guard;
}

template<typename T>
RBTree<T>::~RBTree()
{
    this->delNodes(this->root);

    if (this->guard != nullptr)
    {
        delete this->guard;
    }
}

template<typename T>
void RBTree<T>::add(T val, size_t index)
{
    // Create new node, and temporary helper
    Node<T>* newNode;
    Node<T>* helper;

    // Initialize new node
    newNode = new Node<T>(val, this->root,
                              this->guard, this->guard, true);

    // Check if tree contains any nodes
    if (newNode->parent == this->guard)
    {
        this->root = newNode;
    }
    else
    {
        // Place new node in tree, like in regular BST
        while (true)
        {
            if (val < newNode->parent->getVal())
            {
                if (newNode->parent->l_child == this->guard)
                {
                    newNode->parent->l_child = newNode;
                    break;
                }
                newNode->parent = newNode->parent->l_child;
            }
            else
            {
                if (newNode->parent->r_child == this->guard)
                {
                    newNode->parent->r_child = newNode;
                    break;
                }
                newNode->parent = newNode->parent->r_child;
            }
        }
    }


    while (newNode != this->root && newNode->parent->is_red == true)
    {
        if (newNode->parent == newNode->parent->parent->l_child)
        {
            helper = newNode->parent->parent->r_child;

            if (helper->is_red == true)
            {
                newNode->parent->is_red = false;
                helper->is_red = false;
                newNode->parent->parent->is_red = true;
                newNode = newNode->parent->parent;
                continue;
            }

            if (newNode == newNode->parent->r_child)
            {
                newNode = newNode->parent;
                this->lRot(newNode);
            }

            newNode->parent->is_red = false;
            newNode->parent->parent->is_red = true;
            this->rRot(newNode->parent->parent);
            break;
        }
        else
        {
            helper = newNode->parent->parent->l_child;

            if (helper->is_red == true)
            {
                newNode->parent->is_red = false;
                helper->is_red = false;
                newNode->parent->parent->is_red = true;
                newNode = newNode->parent->parent;
                continue;
            }

            if (newNode == newNode->parent->l_child)
            {
                newNode = newNode->parent;
                this->rRot(newNode);
            }

            newNode->parent->is_red = false;
            newNode->parent->parent->is_red = true;
            this->lRot(newNode->parent->parent);
            break;
        }
    }

    this->root->is_red = false;
    this->num_of_elements++;
}

template<typename T>
Node<T>* RBTree<T>::find(const T& key)
{
    if (this->root == this->guard)
    {
        return nullptr;
    }

    Node<T>* helper = this->root;

    do
    {
        if (key == helper->getVal())
        {
            return helper;
        }

        if (key < helper->getVal())
        {
            helper = helper->l_child;
        }

        if (key > helper->getVal())
        {
            helper = helper->r_child;
        }
    } while (helper != this->guard);

    return nullptr;
}

template<typename T>
void RBTree<T>::erase(size_t key)
{
    Node<T>* nodeToRemove = this->find(key);

    // Check if node with wanted key exists
    if (nodeToRemove == nullptr)
    {
        throw std::invalid_argument("Node doesn't exist");
    }

    Node<T>* helperOne;
    Node<T>* helperTwo;

    if (nodeToRemove->l_child == this->guard
        || nodeToRemove->r_child == this->guard)
    {
        helperOne = nodeToRemove;
    }
    else
    {
        helperOne = this->successor(nodeToRemove);
    }

    if (helperOne->l_child != this->guard)
    {
        helperTwo = helperOne->l_child;
    }
    else
    {
        helperTwo = helperOne->r_child;
    }

    helperTwo->parent = helperOne->parent;

    if (helperOne->parent == this->guard)
    {
        this->root = helperTwo;
    }
    else
    {
        if (helperOne == helperOne->parent->l_child)
        {
            helperOne->parent->l_child = helperTwo;
        }
        else
        {
            helperOne->parent->r_child = helperTwo;
        }
    }

    if (helperOne != nodeToRemove)
    {
        nodeToRemove->getVal() = helperOne->getVal();
    }

    if (helperOne->is_red == false)
    {
        this->delFix(helperTwo);
    }

    this->num_of_elements--;
}

template<typename T>
void RBTree<T>::print()
{
    if (this->root != this->guard)
    {
        // Calculate tree depth
        size_t depth = 0;
        getDepth(this->root, depth, 0);

        // Calculate maximum number of nodes
        size_t size = pow(2, depth);

        // Create table to get access to all nodes
        auto** table = new Node<T>*[size];
        for (size_t i = 0; i < size; i++)
        {
            table[i] = nullptr;
        }

        // Place nodes inside table
        placeNodes(this->root, table, 0);

        // Get handler for console manipulation
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

        bool outOfBound = false;
        size_t first = 0;
        size_t last = 1;
        size--;

        // Calculate the maximum number of nodes at the current heap level
        size_t space = size;

        while (!outOfBound)
        {
            // Print space before each heap level
            std::cout << std::string(space / 2 * 3, ' ');

            // Print nodes on current heap level
            for (size_t i = first; i < last; i++)
            {
                if (i >= size)
                {
                    outOfBound = true;
                    break;
                }

                // Check if table on current index is not empty
                if (table[i] != nullptr)
                {
                    // Display node
                    int color = table[i]->is_red ? 12 : 8;
                    SetConsoleTextAttribute(hConsole, color);
                    std::cout << '[' << table[i]->value << ']' << std::string(space * 3, ' ');
                    continue;
                }

                // Display emply space instead of node
                std::cout << "   " << std::string(space * 3, ' ');
            }
            std::cout << "\n\n";

            // Change indexes or last and first node on each heap level
            first = last;
            last = 2 * last + 1;

            // Change size of space between nodes
            space = space / 2;
        }

        // Set back default console color
        SetConsoleTextAttribute(hConsole, 15);

        // Delete table for storing nodes
        delete[] table;

        return;
    }
    std::cout << "Data structure is empty" << std::endl;
}


template<typename T>
Node<T>* RBTree<T>::successor(Node<T>* node)
{
    // Check if r_child child exists
    if (node->r_child != this->guard)
    {
        return this->min(node->r_child);
    }

    Node<T>* helper = node->parent;
    while (helper != this->guard && node == helper->r_child)
    {
        node = helper;
        helper = helper->parent;
    }
    return helper;
}

template<typename T>
Node<T>* RBTree<T>::min(Node<T>* node)
{
    // Loop while l_child child exists
    while (node->l_child != this->guard)
    {
        node = node->l_child;
    }
    return node;
}

template<typename T>
const Node<T>* RBTree<T>::find(const T& key, const Node<T>* node)
{
    // Check if node exists
    if (node == this->guard)
    {
        return nullptr;
    }

    // Check if node store wanted value
    if (key == node->getVal())
    {
        return node;
    }

    // Look for node in the r_child branch of tree
    if (key > node->getVal())
    {
        return find(key, node->r_child);
    }

    // Look for node in the l_child branch of tree
    return find(key, node->l_child);
}

template<typename T>
void RBTree<T>::lRot(Node<T> *node)
{
    // Create two temporary pointers
    Node<T>* child;
    Node<T>* parent;

    child = node->r_child;

    // Check if r_child child exits
    if (child != this->guard)
    {
        parent = node->parent;
        node->r_child = child->l_child;

        // Check if exists l_child child of r_child child
        if (node->r_child != this->guard)
        {
            node->r_child->parent = node;
        }

        // Swap nodes
        child->l_child = node;
        child->parent = parent;
        node->parent = child;

        // Check if parent exists
        if (parent != this->guard)
        {
            if (parent->l_child == node)
            {
                parent->l_child = child;
                return;
            }
            parent->r_child = child;
            return;
        }
        this->root = child;
    }
}


template<typename T>
void RBTree<T>::rRot(Node<T>* node)
{
    // Create two temporary pointers
    Node<T>* child;
    Node<T>* parent;

    child = node->l_child;

    // Check if l_child child exits
    if (child != this->guard)
    {
        parent = node->parent;
        node->l_child = child->r_child;

        // Check if exists r_child child of l_child child
        if (node->l_child != this->guard)
        {
            node->l_child->parent = node;
        }

        // Swap nodes
        child->r_child = node;
        child->parent = parent;
        node->parent = child;

        // Check if parent exists
        if (parent != this->guard)
        {
            if (parent->l_child == node)
            {
                parent->l_child = child;
                return;
            }
            parent->r_child = child;
            return;
        }
        this->root = child;
    }
}

template<typename T>
void RBTree<T>::delFix(Node<T>* node)
{
    Node<T>* helper;

    // Fix tree structure and node colors
    while (node != this->root && node->is_red == false)
    {
        if (node == node->parent->l_child)
        {
            helper = node->parent->r_child;

            if (helper->is_red == true)
            {
                helper->is_red = false;
                node->parent->is_red = true;
                this->lRot(node->parent);
                helper = node->parent->r_child;
            }

            if (helper->l_child->is_red == false
                && helper->r_child->is_red == false)
            {
                helper->is_red = true;
                node = node->parent;
            }
            else
            {
                if (helper->r_child->is_red == false)
                {
                    helper->l_child->is_red = false;
                    helper->is_red = true;
                    this->rRot(helper);
                    helper = node->parent->r_child;
                }
                helper->is_red = helper->parent->is_red;
                node->parent->is_red = false;
                helper->r_child->is_red = false;
                this->lRot(node->parent);
                node = this->root;
            }
        }
        else
        {
            helper = node->parent->l_child;

            if (helper->is_red == true)
            {
                helper->is_red = false;
                node->parent->is_red = true;
                this->rRot(node->parent);
                helper = node->parent->l_child;
            }

            if (helper->r_child->is_red == false
                && helper->l_child->is_red == false)
            {
                helper->is_red = true;
                node = node->parent;
            }
            else
            {
                if (helper->l_child->is_red == false)
                {
                    helper->r_child->is_red = false;
                    helper->is_red = true;
                    this->lRot(helper);
                    helper = node->parent->l_child;
                }
                helper->is_red = helper->parent->is_red;
                node->parent->is_red = false;
                helper->l_child->is_red = false;
                this->rRot(node->parent);
                node = this->root;
            }
        }
    }
    node->is_red = false;
}

template<typename T>
void RBTree<T>::delNodes(Node<T>* node)
{
    // Check if current node is not the guardian
    if (node != this->guard)
    {
        delNodes(node->l_child);
        delNodes(node->r_child);
        delete node;
    }
}

template<typename T>
void RBTree<T>::getDepth(Node<T>* node, size_t& maxDepth, size_t currentDepth)
{
    // Increase depth
    currentDepth++;

    // Chech if calculated depth is grater than max depth
    if (currentDepth > maxDepth)
    {
        maxDepth = currentDepth;
    }

    // Check if l_child child is not guardian
    if (node->l_child != this->guard)
    {
        getDepth(node->l_child, maxDepth, currentDepth);
    }

    // Check if r_child child is not guardian
    if (node->r_child != this->guard)
    {
        getDepth(node->r_child, maxDepth, currentDepth);
    }
}

template<typename T>
void RBTree<T>::placeNodes(Node<T>* node, Node<T>** table, const size_t& index)
{
    // Place node in table
    table[index] = node;

    // Check if exists l_child child
    if (node->l_child != this->guard)
    {
        placeNodes(node->l_child, table, 2 * index + 1);
    }

    // Check if exists r_child child
    if (node->r_child != this->guard)
    {
        placeNodes(node->r_child, table, 2 * index + 2);
    }
}

template<typename T>
RBTree<T> &RBTree<T>::operator=(const std::vector<T> &origin)
{
    this->clear();
    for(int i =0; i<origin.size();i++)
        add(origin[i]);
    return *this;
}

template<typename T>
void RBTree<T>::clear()
{
    while(this->num_of_elements)
        erase(root->getVal());
}

#endif
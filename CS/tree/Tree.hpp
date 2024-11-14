//
// Created by mason on 11/13/2024.
//
#include <iostream>
#ifndef TREE_TREE_HPP
#define TREE_TREE_HPP

struct Node
{
public:
    int value;
    Node* left = nullptr;
    Node* right = nullptr;
    Node* parent = nullptr;
    bool present = true;

    Node();
    Node(int value);

};

class Tree {
public:
    Node *root = nullptr;

    Tree();
    Tree(int value);
    ~Tree();

    void insertValue(int value);
    void recAddValue(int value, Node* ptr);
    std::string preOrder();
    std::string recPreOrder(Node* ptr);
    std::string inOrder();
    std::string recInOrder(Node* ptr);
    std::string postOrder();
    std::string recPostOrder(Node* ptr);
    bool findValue(int value);
    bool removeValue(int value);
    int findLarger(int value);

};
#endif //TREE_TREE_HPP

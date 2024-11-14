//
// Created by mason on 11/4/2024.
//
#include<iostream>
#include<stack>
#include<queue>
#include <sstream>
#include <iomanip>
#ifndef BINARYTREE_PARSETREE_HPP
#define BINARYTREE_PARSETREE_HPP

struct Node
{
public:
    std::string value = "";
    Node* left = nullptr;
    Node* right = nullptr;
    Node* parent = nullptr;

    Node();
    Node(std::string value);
    Node(char value);

};

class ParseTree
{
public:
    Node* root = nullptr;

    ParseTree();
    ParseTree(std::string value);
    ~ParseTree();

    Node* parse(std::string value);
    std::string display();
    std::string preOrder ();
    std::string inOrder ();
    std::string postOrder ();
    bool isOperand(char value);
    bool isOperator(char value);
    bool higherPrec(char comp1, char comp2);
    Node* parseInOrder(std::string);

};


#endif //BINARYTREE_PARSETREE_HPP

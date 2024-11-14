//
// Created by mason on 11/13/2024.
//

#include "Tree.hpp"

Node::Node(){}
Node::Node(int value){this->value = value;}
Tree::Tree(){}
Tree::Tree(int value){root = new Node(value);}
Tree::~Tree(){}

void Tree::insertValue(int value)
{

    if (root == nullptr)
    {
        Node* temp = new Node(value);
        root = temp;
    }
    else
    {
        recAddValue( value, root);
    }
}

void Tree::recAddValue(int value, Node* ptr)
{

    if (value == ptr->value && !ptr->present)
    {
        ptr->present = true;
    }
    else if (value < ptr->value)
    {
        if (ptr->left == nullptr)
        {
            Node *temp = new Node(value);
            ptr->left = temp;
        }
        else (recAddValue(value, ptr->left));
    }
    else
    {
        if (ptr->right == nullptr)
        {
            Node* temp = new Node(value);
            ptr->right = temp;
        }
        else
        {
            recAddValue(value, ptr->right);
        }
    }
}


std::string Tree::preOrder()
{
    std::string buffer;

    if (root == nullptr)
    {
        return buffer;
    }
    else
    {
        buffer += recPreOrder(root);
    }

    return buffer;

}

std::string Tree::recPreOrder(Node* ptr) {

    std::string buffer;
    Node* temp = ptr;

  if (ptr)
  {
      if (!temp->present)
      {
          buffer += (std::to_string(temp->value) + "D" + " ");
      }
      else
      {
          buffer += (std::to_string(temp->value) + " ");
      }
        buffer += recPreOrder(temp->left);
        buffer += recPreOrder(temp->right);
        }

    return buffer;

}

std::string Tree::inOrder()
{
    std::string buffer;

    if (root == nullptr)
    {
        return buffer;
    }
    else
    {
        buffer += recInOrder(root);
    }

    return buffer;
}

std::string Tree::recInOrder(Node* ptr)
{
    std::string buffer;
    Node* temp = ptr;

    if (ptr)
    {
        buffer += recInOrder(temp->left);
        if (!temp->present)
        {
            buffer += (std::to_string(temp->value) + "D" + " ");
        }
        else
        {
            buffer += (std::to_string(temp->value) + " ");
        }
        buffer += recInOrder(temp->right);
    }

    return buffer;
}


std::string Tree::postOrder()
{
    std::string buffer;

    if (root == nullptr)
    {
        return buffer;
    }
    else
    {
        buffer += recPostOrder(root);
    }

    return buffer;
}

std::string Tree::recPostOrder(Node* ptr)
{
    std::string buffer;
    Node* temp = ptr;

    if (ptr)
    {
        buffer += recPostOrder(temp->left);
        buffer += recPostOrder(temp->right);
        if (!temp->present)
        {
            buffer += (std::to_string(temp->value) + "D" + " ");
        }
        else
        {
            buffer += (std::to_string(temp->value) + " ");
        }
    }

    return buffer;
}

bool Tree::findValue(int value)
{
    Node* ptr = root;

    while (ptr)
    {
        if (ptr->value == value && ptr->present)
        {
            return true;
        }

        if (value < ptr->value)
        {
            ptr = ptr->left;
        }
        else
        {
            ptr = ptr->right;
        }
    }

    return false;
}

bool Tree::removeValue(int value)
{
    Node* ptr = root;

    while (ptr)
    {
        if (ptr->value == value && ptr->present)
        {
            ptr->present = false;
            return true;
        }

        if (value < ptr->value)
        {
            ptr = ptr->left;
        }
        else
        {
            ptr = ptr->right;
        }
    }

    return false;
}

int Tree::findLarger(int value) //close but not quite right.
{
   bool found = findValue(value);

    if (found)
    {
        return value;
    }
    else
    {
        Node *temp = root;


        while (temp->left || temp->right)
        {
            if (value > temp-> value && value < temp->right->value)
            {
                return temp->right->value;
            }
            else if (value < temp->value)
            {
                temp = temp->left;
            }
            else
            {
                temp = temp->right;
            }
        }
    }

  return -1;
}
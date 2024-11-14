//
// Created by mason on 11/11/2024.
//

#include "parsetreesandbox.hpp"

Node::Node(){}
Node::Node(std::string value){this->value = value;}
Node::Node(char value){this->value = value;}
ParseTree::ParseTree(){}
ParseTree::ParseTree(std::string value){root = new Node(value);}
ParseTree::~ParseTree(){}

Node* ParseTree::parse(std::string value)
{
    std::stack<Node*> theStack;
    int i = 0;

    while (value[i] != '\0')
    {
        if (isOperand (value[i]))
        {
            theStack.push(new Node(std::string(1,value[i++])));
        }
        else
        {
            Node* temp = new Node((std::string(1,value[i++])));
            temp->right = theStack.top();
            theStack.pop();

            temp->left = theStack.top();
            theStack.pop();

            theStack.push(temp);
        }
    }

    return theStack.top();
}


std::string ParseTree::display()
{
    const int PAGE_WIDE = 64;

    Node* dummy = nullptr;
    std::string emptyNode;
    std::stringstream buffer;
    std::queue<Node*> theQueue;
    bool more = true;
    int currNodes = 1;

    theQueue.push( parse(root->value));

    while (more)
    {
        more = false;
        int offset = PAGE_WIDE/(currNodes*2);

        for (int i = 0; i < currNodes; i++)
        {
            Node* ptr = theQueue.front();
            theQueue.pop();

            if (i == 1)
            {
                offset *= 2;
            }

            if (ptr != dummy)
            {
                buffer << std::setw(offset) << ptr->value;


                if (ptr->left)
                {
                    more = true;
                    theQueue.push(ptr->left);
                }
                else {
                    (theQueue.push(dummy));
                }

                if (ptr->right)
                {
                    more = true;
                    theQueue.push(ptr->right);
                }
                else {
                    (theQueue.push(dummy));
                }
            }
            else
            {
                buffer << std::setw(offset) << emptyNode;
                theQueue.push(dummy);
                theQueue.push(dummy);
            }
        }

        currNodes *= 2;
        buffer << std::endl;

    }

    return buffer.str();

}

std::string ParseTree::preOrder ()
{
    std::stack<std::string> theStack;
    std::string answer;
    int i = 0;
    std::string op1, op2;

    while (root->value[i] != '\0')
    {
        if (isOperand(root->value[i]))
        {
            theStack.push(std::string(1,root->value[i++]));
        }
        else
        {
            op1 = theStack.top();
            theStack.pop();

            if (!theStack.empty())
            {
                op2 = theStack.top();
                theStack.pop();
            }

            theStack.push(std::string(1, root->value[i]) + op2 + op1);

            i++;
        }
    }

    while (!theStack.empty())
    {
        answer += theStack.top();
        theStack.pop();
    }

    return answer;

}
std::string ParseTree::inOrder ()
{
    std::stack<std::string> theStack;
    std::string answer;
    int i = 0;
    std::string op1, op2;

    while (root->value[i] != '\0')
    {
        if (isOperand(root->value[i]))
        {
            theStack.push(std::string(1, root->value[i++]));
        }
        else
        {
            op1 = theStack.top();
            theStack.pop();

            if (!theStack.empty())
            {
                op2 = theStack.top();
                theStack.pop();
            }

            theStack.push("(" + op2 + root->value[i] + op1 + ")");

            i++;
        }
    }

    while (!theStack.empty())
    {
        answer += theStack.top();
        theStack.pop();
    }

    return answer;
}

std::string ParseTree::postOrder ()
{
    std::stack<char> theStack;
    std::string answer;
    int i = 0;

    while (root->value[i] != '\0')
    {
        if (isOperand(root->value[i]))
        {
            answer += root->value[i++];
        }
        else if (root->value[i] == '(')
        {
            theStack.push(root->value[i++]);
        }
        else if (root->value[i] == ')')
        {
            while (theStack.top() != '(')
            {
                answer += theStack.top();
                theStack.pop();
            }
            theStack.pop();
            i++;
        }
        else
        {
            while (!theStack.empty() && higherPrec(theStack.top(), root->value[i]))
            {
                answer += theStack.top();
                theStack.pop();
            }
            theStack.push(root->value[i++]);
        }

        while (!theStack.empty())
        {
            answer += theStack.top();
            theStack.pop();
        }
    }

    return answer;
}

bool ParseTree::isOperand(char value)
{
    if (value >= 'A' && value <= 'Z')
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool ParseTree::isOperator(char value)
{

    if (value == '+' || value == '-' || value == '*' || value == '/')
    {
        return true;
    }
    else {
        return false;
    }

}

bool ParseTree::higherPrec(char comp1, char comp2)
{
    if ((comp1 == '*' || comp1 == '/') && (comp2 == '+' || comp2 == '-'))
    {
        return true;
    }
    else
    {
        return false;
    }
}
//
// Created by mason on 10/23/2024.
//

#include "ChainHash.hpp"

ChainHash::ChainHash():array(new ChainLink[size]){}
ChainHash::ChainHash(int size): size(size), array(new ChainLink[size]){}
ChainHash::~ChainHash(){delete [] array;}
ChainLink::ChainLink(): data("_empty_"), next(nullptr){}
ChainLink::ChainLink(std::string value): data(value), next(nullptr){}

int ChainHash::hashFunc(std::string value){
    int code = 0;
    for (int i = 0; i < value.length(); i++)
    {
        code *= 128;
        code += (value[i]);
        code %= size;
    }

    return code;
}


void ChainHash::addItem(std::string value){

    if (count == size * 2)
    {
        resize();
    }
    int index = hashFunc(value);

   // std::cout << "adding " << value << '\n';//test
    if (array[index].data == empty)
    {
       // std::cout << "index is empty" << '\n';//test
        array[index].data = value;
    }
    else
    {//per dr m, I need to initialize my array to nullptr and my temp variable should be a pointer
        ChainLink* newLink = new ChainLink(value);
        ChainLink* temp = array +index;
        while (temp->getNext())
        {
           temp = temp->getNext();
        }
        temp->setNext(newLink);
    }
    count++;
}

bool ChainHash::findItem(std::string value){

    int index = hashFunc(value);

    ChainLink* temp = (array + index);

    while (temp)
    {
        if (temp->data == value)
        {
            return true;
        }
        else
        {
            temp = temp->getNext();
        }
    }
    return false;
}

void ChainHash::removeItem(std::string value) {

    bool done = false;

    int index = hashFunc(value);

    if (array + index != nullptr) {
        ChainLink *temp = array + index;

        if (temp->data == value) {
            done = true;
            count--;
            if (array[index].getNext()) {
                array[index].getNext();
                delete temp;
            } else
            {array[index].data = empty;
            array[index].next = nullptr;}
        } else {
            while (temp->getNext() && !done) {
                if (temp->getNext()->getData() == value) {
                    count--;
                    ChainLink *temp2 = temp->getNext();
                    temp->setNext(temp->getNext()->getNext());
                    delete temp2;
                    done = true;
                } else {
                    temp = temp->getNext();
                }
            }
        }
    }
}

std::string ChainHash::displayTable()
{
    std::string answer;

    for (int i = 0; i < size; i++)
    {
        ChainLink* index = array + i;

        while (index)
        {
            answer += index->data;
            answer += " ";
            index = index->getNext();
        }
        answer += '\n';
    }
    return answer;
}

void ChainHash::resize()
{
    ChainLink* tempArray = new ChainLink[size];
    int tempSize = size;

    for (int i = 0; i < size;i++) {

        tempArray[i] = array[i];
    }

    size*=2;
    getPrime(size);

    ChainHash* temp2 = new ChainHash(size);

    for (int i = 0; i < tempSize;i++)
    {
        ChainLink* temp3 = tempArray + i;

        while (temp3)
        {
            temp2->addItem(temp3->data);
            temp3 = temp3->next;
        }

    }

    array = temp2->array;
    count = temp2->count;

}

void ChainHash::getPrime(int& value)
{
    while (!isPrime(value))
    {
        value++;
    }
}

bool ChainHash::isPrime(int value)
{
    if (value <= 1)
    {
        return false;
    }

    int limit = sqrt(value);

    for (int i = 2; i <= limit; i++)
    {
        if (value % i == 0)
        {
            return false;
        }
    }
    return true;
}
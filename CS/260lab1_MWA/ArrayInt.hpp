//
// Created by mason on 9/30/2024.
//

#ifndef INC_260LAB1_MWA_ARRAYINT_HPP
#define INC_260LAB1_MWA_ARRAYINT_HPP

#include <string>

class ArrayInt {
private:
    const static int SIZE = 10;
    int size;
    int lastIndex;
    int * theArray;
    bool empty = true;

public:
    // constructor and destructor
    ArrayInt(int size = SIZE);
    ~ArrayInt();

    // return the size or resize to larger
    int getSize() { return size; }
    int getLastIndex() {return lastIndex;}

    void append (int value);
    int getLast();
    void deleteLast();
    void resize (int value);
    std::string listElements();
};

#endif //INC_260LAB1_MWA_ARRAYINT_HPP

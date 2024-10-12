#include <iostream>

void append (int array[], int size, int &count, int value)
{
    array[count++]=value;
}

void insert(int array[], int size, int &count, int index, int value)
{
    for (int i = count; i > index; i--)
    {
        array[i]=array[i-1];
    }
    array[index]=value;
    count++;
}

int removeLast (int array[], int size, int &count)
{
    return array[--count];
}

int removeItem (int array[], int size, int &count, int index)
{
    int value = array[index];

    for (int i = index; i < count; i++)
    {
        array[i] = array [i+1];
    }

    count -=1; // the reading explicitly states to put this before for loop, but I need to pull the existing
    // value from that space before decrementing the count.
    return value;
}

bool find (int array[],int size, int count, int value)
{
    bool found = false;

    for (int i = 0; i < count && !found; i++)
    {
        if (array[i] == value) found = true;
    }
    return found;
}

bool removeValue(int array[], int size, int &count, int value)
{
    bool found = false;

    for (int i = 0; i < count && !found; i++)
    {
        if (array[i] == value)
        {
            for (int j = i; j < count; j++)
            {
                array[j]=array[j+1];
            }
            count -=1; // same as removeItem - book says to put this before loop
            found = true;
        }
    }
    return found;
}

bool removeValueDisordered(int array[], int size, int &count, int value) {
    bool found = false;
    for (int i = 0; i < count && !found; i++) {
        if (array[i] == value) {
            array[i] = array[count];
            count -= 1; // same problem as removeValue and removeItem
            found = true;
        }
    }
    return found;
}

int main()
{
    int size = 8;
    int count = 3;
    int value = 3;
    int index = 2;

    int array[]{1,2,3,4};

    //append(array, size, count, value);
    //insert(array, size, count, index, value);
    //removeLast(array, size, count);
    //removeItem(array, size, count, index);
    //std::cout << find(array, size, count, value) << '\n';
    //removeValue(array, size, count, value);
    //removeValueDisordered(array, size, count, value);

for (int i = 0; i <= count; i++)
{
    std::cout << array[i] <<'\n';
}

    return 0;
}

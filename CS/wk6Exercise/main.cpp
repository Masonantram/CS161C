#include <iostream>

int main()
{
    class Rectangle
    {
        int length;
        int width;

    public:
        void setValue () {length = 0, width = 0;}
        void setValue (int side) {length = side, width = side;}
        void setValue (int height, int reach) { length = height, width = reach;}
        void setLength (int side) {length = side;}
        void setWidth (int side) {width = side;}


        int getLength () {return length;}
        int getWidth () {return width;}
        int getPerimeter () {return (length * 2) + (width * 2);}
        int getArea () {return length * width;}
        bool isSquare () {return length == width;}
    };
    return 0;
}


/*
 * Define a class Rectangle with two private integer variables, length and width.

It should have three constructors; default sets both length and width to zero, overloaded with one parameter, sets length
and width both to that value, and overloaded with two parameters, sets the length to the first parameter and width to the second.

There should be setters and getters for both length and width. In addition, you need three extra methods, getPerimeter,
 getArea, and isSquare (returns true for length == width).  Your methods should all use this to access the object variables.
 */
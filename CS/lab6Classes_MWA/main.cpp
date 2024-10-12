#include <iostream>

int main() {

    class Student
    {
        std::string name;
        int age;

    public:
        Student () {name = " ", age = 0;}
        Student (std::string name, int age) { this -> name = name; this -> age = age;}

        std::string getName() {return name;}
        int getAge() {return age;}

        ~Student();

    };

    return 0;
}


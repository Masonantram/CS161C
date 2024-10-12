// Created by mason on 3/7/2024.

#ifndef LAB5_MWA_HEADER_HPP
#define LAB5_MWA_HEADER_HPP

const int MIN = 5, MAX = 20, COLUMN = 35;

class Student
{
    std::string name;
    int age;
public:
    //constructors
    Student ();
    Student (std::string name, int age);
    //public methods
    void setName (std::string name);
    void setAge(int age) ;
    //getters
    const std::string getName() ;
    const float getAge() ;
    //destructor
    ~Student() {};

};

int getInteger (int min, int max);
Student* createArray (int size);
void displayArrays (Student* studentArray, int records);
bool sortByName (Student &a, Student &b);

#endif //LAB5_MWA_HEADER_HPP

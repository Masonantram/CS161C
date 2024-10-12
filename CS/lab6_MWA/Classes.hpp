// Created by mason on 3/7/2024.

#include <string>

#ifndef LAB6_MWA_CLASSES_HPP
#define LAB6_MWA_CLASSES_HPP

class Student
{
    std::string name;
    int age;

public:
    //constructors
    Student() ;
    Student (std::string name, int age);
    //setters
    void setName (std::string name) { this -> name = name;}
    void setAge(int age) {this -> age = age;}
    //getters
    const std::string getName()  {return name;}
    const float getAge(){return age;}
    //destructor
    ~Student() {};

};

#endif //LAB6_MWA_CLASSES_HPP

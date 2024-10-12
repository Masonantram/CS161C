// Created by mason on 3/17/2024.

#include <istream>
#include "Player Class.hpp"

//Person constructors
Person::Person (){firstName = " "; lastName = " "; age = 0;};
Person::Person(std::string firstName, std::string lastName, int age)
{
    this->firstName = firstName;
    this->lastName = lastName;
    this->age = age;
}


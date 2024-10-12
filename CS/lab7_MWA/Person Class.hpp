// Created by mason on 3/17/2024.

#ifndef LAB7_MWA_PERSON_CLASS_HPP
#define LAB7_MWA_PERSON_CLASS_HPP

class Person {

    std::string firstName;
    std::string lastName;
    int age;

public:
    //constructors
    Person ();
    Person(std::string firstName, std::string lastName, int age);
    //setters
    void setFirstName(std::string firstName) { this->firstName = firstName; }
    void setLastName(std::string lastName) { this->lastName = lastName; }
    void setAge(int age) { this->age = age; }
    //getters
    std::string const getFirstName() { return firstName; }
    std::string const getLastName() { return lastName; }
    int const getAge() { return age; }
    //destructor
    virtual ~Person() {};
};

#endif //LAB7_MWA_PERSON_CLASS_HPP

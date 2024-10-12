#include <iostream>
#include "header.hpp"

Person::Person ()  {firstName = "1 "; lastName = "2 "; age = 0;}

Person::Person(std::string firstName, std::string lastName, int age)
{
    this->firstName = firstName;
    this->lastName = lastName;
    this->age = age;
}

void Person::setFirstName(std::string firstName) { this->firstName = firstName; }
void Person::setLastName(std::string lastName) { this->lastName = lastName; }
void Person::setAge(int age) { this->age = age; }

std::string Person::getFirstName() { return firstName; }
std::string Person::getLastName() { return lastName; }

int Person::getAge() { return age; }



//Player::Player() {player = new Person;}
Player::Player () {}
Player::Player (std::string firstName, std::string lastName, int age) {}

std::string Player::getPlayerName() {return (player ->getFirstName() + player ->getLastName());}
int Player::getPlayerAge() {return player -> getAge();}

//Ranger::Ranger () {ranger = new Player;}

Ranger::Ranger (std::string firstName, std::string lastName, int age) {};

//learn about initialization lists



std::string Ranger::getClassName() {return "Ranger ";}
std::string Ranger::getAction() {return "Shoots arrows ";}

// Created by mason on 3/17/2024.
#include "Player Class.hpp"

//Player constructors
Player::Player() {player = new Person;}
Player::Player (std::string firstName, std::string lastName, int age) {player = new Person (firstName, lastName, age);}

//Ranger constructors
Ranger::Ranger () {ranger = new Player;}
Ranger::Ranger (const std::string& firstName, const std::string& lastName, const int age):Player (firstName, lastName, age)
{
    ranger = new Player;
    Player::setFirstName(firstName);
    Player::setLastName(lastName);
    Player::setAge(age);
}

//Wizard constructors
Wizard::Wizard() {wizard = new Player;}
Wizard::Wizard (const std::string& firstName, const std::string& lastName, const int age):Player (firstName, lastName, age)
{
    wizard = new Player;
    Player::setFirstName(firstName);
    Player::setLastName(lastName);
    Player::setAge(age);
}

//Rogue constructors
Rogue::Rogue() {rogue = new Player();}
Rogue::Rogue (const std::string& firstName, const std::string& lastName, const int age):Player (firstName, lastName, age)
{
    rogue = new Player;
    Player::setFirstName(firstName);
    Player::setLastName(lastName);
    Player::setAge(age);
}

//Priest constructors
Priest::Priest () {priest = new Player();}
Priest::Priest (const std::string& firstName, const std::string& lastName, const int age):Player (firstName, lastName, age)
{
    priest = new Player;
    Player::setFirstName(firstName);
    Player::setLastName(lastName);
    Player::setAge(age);
}



// Created by mason on 3/17/2024.

#include <iostream>
#include "Person Class.hpp"

#ifndef LAB7_MWA_PLAYER_CLASS_HPP
#define LAB7_MWA_PLAYER_CLASS_HPP

class Player : public Person
{
    Person* player;

public:
    //constructors
    Player();
    Player (std::string firstName, std::string lastName, int age);

    //getters
    std::string getPlayerName() {return (player ->getFirstName() + player ->getLastName());}
    int getPlayerAge() {return player -> getAge();}
    virtual const std::string getClassName()  {return "Player";}
    virtual const std::string getAction() {return "Action";}

    virtual ~Player() {delete player; std::cout << "deleted player"<< '\n';}
};

class Ranger : public Player
{
    Player* ranger;

public:
    Ranger ();
    Ranger (const std::string& firstName, const std::string& lastName, const int age);

    std::string const getClassName() override {return "Ranger";}
    std::string const getAction() override {return "Shoots arrows ";}
};

class Wizard : public Player
{
    Player* wizard;

public:
    Wizard();
    Wizard (const std::string& firstName, const std::string& lastName, const int age);

    std::string const getClassName() override {return "Wizard";}
    std::string const getAction() override {return "casts fireballs";}
};

class Rogue : public Player
{
    Player* rogue;

public:
    Rogue();
    Rogue (const std::string& firstName, const std::string& lastName, const int age);

    std::string const getClassName() override {return "Rogue";}
    std::string const getAction() override {return "picks pockets";}
};

class Priest : public Player
{
    Player* priest;

public:
    Priest();
    Priest (const std::string& firstName, const std::string& lastName, const int age);

    std::string const getClassName() override {return "Priest";}
    std::string const getAction() override {return "heals";}

};


#endif //LAB7_MWA_PLAYER_CLASS_HPP

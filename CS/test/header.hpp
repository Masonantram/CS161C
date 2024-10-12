#include <iostream>

#ifndef TEST_HEADER_HPP
#define TEST_HEADER_HPP


class Person {

private:
    std::string firstName;
    std::string lastName;
    int age;

public:

    Person () ;
    Person(std::string firstName, std::string lastName, int age);

    void setFirstName(std::string firstName);
    void setLastName(std::string lastName);
    void setAge(int age);

    std::string getFirstName();
    std::string getLastName() ;

    int getAge();

    ~Person() {std::cout << "deleted person " << '\n';};
};

class Player : public Person
{
    Person* player;

public:

    Player() {player = new Player;};
    Player (std::string firstName, std::string lastName, int age) {player = new Player;}

    virtual ~Player() {delete player; std::cout << "deleted player"<< '\n';}

    void setPlayer (std::string firstName, std::string lastName, int age);

    std::string getPlayerName();
    int getPlayerAge() ;
    virtual std::string getClassName() {return "Player";}
    virtual std::string getAction() {return "Action";}
};

class Ranger : public Player
{
    Player* ranger;

public:
    Ranger ();
    Ranger (std::string firstName, std::string lastName, int age);

    ~Ranger() {delete ranger;};

    std::string getClassName();
    std::string getAction();
};

#endif //TEST_HEADER_HPP

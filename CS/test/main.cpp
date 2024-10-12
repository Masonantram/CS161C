#include <iostream>
#include "header.hpp"

int main()
{

    Ranger* playery = new Ranger("test", "ing", 15);

    playery -> setFirstName("test");
    playery -> setLastName("ing");
    playery -> setAge(6);

    std::cout << playery -> getPlayerName() << " ";
    std::cout << playery -> getPlayerAge() << " ";
    std::cout << playery -> getClassName() << " ";
    std::cout << playery -> getAction() << " ";

   // delete playery;


    return 0;
}

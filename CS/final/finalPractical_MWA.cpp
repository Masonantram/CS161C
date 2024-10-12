
#include "finalPractical_MWA.h"
#include<iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <limits>

void getWord(std::string &theWord)
{
    std::stringstream reader;
    static int counter = 0;
    std::string lastWord;

    std::ifstream wordFile("words.txt");

    if (!wordFile.good() || wordFile.eof())
    {
        theWord = "done";
    }

    do
    {
        reader >> theWord;

        if (theWord == lastWord)
        {
            theWord = "done";
        }

        theWord = lastWord;

    } while (!wordFile.eof() || theWord != "done");

    wordFile.close();
}

char getLetter()
{
    std::string theGuess;
    char character = theGuess[0];

    std::cout << "please enter a letter" << std::endl;
    std::cin >> theGuess;
    // theGuess.clear();
    // std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n')

    return character;
}
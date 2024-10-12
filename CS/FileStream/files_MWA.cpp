// Final lab: File IO
// Name: Mason Antram
// Version: 1.0
//
// Features of this program:
// - it compiles!
// - it will read your txt file and output a new text file with shapes made in the dimensions and symbol of your choice.
//
// Features lacking:
// - It does not produce a proper diamond shape.
// - It does not have a writeShape function; file output is built in to each separate function.
//
// This was a toughie. I met with Ethan at least once for this project but should have at least once more, and still might if he's available.



#include<iostream>
#include<string>
#include<sstream>
#include <fstream>

#include "files_MWA.h"

std::stringstream buffer;

std::string makeRectangle (char symbol, int length, int width) {

     std::ofstream out("outfile.txt", std::ios::app);

        if (out.good())
        {
            for (int j = 1; j <= length; j++)
            {
                for (int i = 1; i <= width; i++)
                {
                    out << symbol;
                    if (i == width) { out << std::endl; }
                }
            }
        }
        out.close();
 return buffer.str();
}

std::string makeSquare (char symbol, int length){

    std::ofstream out("outfile.txt", std::ios::app);

    if (out.good())
    {
        for (int i = 1; i <= length; i++)
        {
            for (int j = 1; j <= length; j++)
            {
                out << symbol;
                if (j == length) { out << std::endl; }
            }
        }
    }
    out.close();
    return buffer.str();
}
std::string makeTriangle (char symbol, int length){

    std::ofstream out("outfile.txt", std::ios::app);

    if (out.good())
    {
        for (int i = 1; i <= length; i++)
        {
            for (int j = 1; j <= i; j++)
            {
                out << symbol;
            }
            out << std::endl;
        }
    }
    out.close();
    return buffer.str();
}

std::string makeDiamond (char symbol, int length){

    std::ofstream out("outfile.txt", std::ios::app);

    if (out.good())
    {
        out << "I'm a shiny diamond" << std::endl;
    }
    out.close();
    return buffer.str();
}

//writeShape (string containing shape, reference parameter for output file)
//writes shapeString to outfile
//returns nothing

// Created by mason on 3/7/2024.

#include "Classes.hpp"

#ifndef LAB6_MWA_HEADER_HPP
#define LAB6_MWA_HEADER_HPP

const int MIN = 5, MAX = 20, COLUMN = 35;

int getInteger (int min, int max);
Student* createStudent (int index);
void displayArrays (Student* studentArray, int records);
bool sortByName (Student &a, Student &b);
inline bool sortByName (Student &a, Student &b) {return a.getName() < b.getName();}

#endif //LAB6_MWA_HEADER_HPP

// Created by mason on 2/26/2024.

#ifndef LAB5_MWA_HEADER_HPP
#define LAB5_MWA_HEADER_HPP

const int MIN = 5, MAX = 20, COLUMN = 25;

struct Student
{
    std::string firstName;
    std::string lastName;
    std::string lNumber;
    float GPA; //(2.00 - 4.20)
};

inline void getLastName (Student& studentArray, int index, std::string lastName[]);
inline void getFirstName (Student& studentArray, int index, std::string firstName[]);
inline void getLNumber (Student& studentArray, int index, std::string lNumber[]);
inline void getGPA (Student& studentArray, int index, const float GPA[]);

int getInteger (int min, int max);
Student* createArray (int size);
void displayArrays (Student* studentArray, int records);
bool sortByLNumber (Student &a, Student &b);
bool sortByName (Student &a, Student &b);
int rando (int& num, int max);
bool binSearch(Student studentArray[], std::string name, int count, int& index);

#endif //LAB5_MWA_HEADER_HPP

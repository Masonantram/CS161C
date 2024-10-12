// Created by mason on 3/21/2024.

#include <iostream>
#include <iomanip>
#ifndef FINAL_MWA_HEADER_HPP
#define FINAL_MWA_HEADER_HPP


struct date
{
    std::string month;
    std::string day;
    std::string year;
};

class Card
{
    std::string series;
    std::string type;
    std::string subType;
    std::string name;
    std::string set;
    bool graded;
    int grade;
    bool firstEdition;

    date buyDate;
    date sellDate;
    float buyPrice;
    float sellPrice;

public:
    Card ();
    Card (const std::string type, const std::string series, const std::string subType, const std::string name, const std::string set,
          const bool graded, const int grade, const bool firstEdition, const date buyDate, const date sellDate, const float buyPrice
            , const float sellPrice);

    void setType (std::string type) {this -> type = type;}
    void setSeries (std::string series) {this -> series = series;}
    void setSubType (std::string subType) {this -> subType = subType;}
    void setName (std::string name) {this -> name = name;}
    void setSet (std::string set) {this -> set = set;}
    void setGraded (bool graded) {this -> graded - graded;}
    void setGrade (int grade) {this -> grade = grade;}
    void setFirstEdition (bool firstEdition) {this -> firstEdition = firstEdition;}
    void setBuyDate (date buyDate) {this -> buyDate = buyDate;}
    void setSellDate (date sellDate) {this -> sellDate = sellDate;}
    void setBuyPrice (float buyPrice) {this -> buyPrice = buyPrice;}
    void setSellPrice (float sellPrice) {this -> sellPrice = sellPrice;}

    std::string getDay (date date) {return date.day;}
    std::string getMonth (date date) {return date.month;}
    std::string getYear (date date) {return date.year;}

    std::string getType() {return this -> type;}
    std::string getSeries () {return this -> series;}
    std::string getSubType () {return this -> subType;};
    std::string getName () {return this -> name;}
    std::string getSet () {return this -> set;}
    bool getGraded () {return this -> graded;}
    int getGrade () {return this -> grade;}
    bool getFirstEdition () {return this -> firstEdition;}
    date getBuyDate () {return this -> buyDate;}
    date getSellDate () {return this -> sellDate;}

    float getBuyPrice () {return this -> buyPrice;}
    float getSellPrice () {return this -> sellPrice;}

    virtual std::string getRarity () {return "N/A";}; //is overridden by cards of the type TCG

};

class TCG: public Card
{
    TCG* TCGCard;
    std::string rarity;

public:
    TCG () ;
    TCG  (const std::string type, const std::string series, const std::string subType, const std::string name, const std::string set,
          const bool graded,const int grade, const bool firstEdition, const date buyDate, const date sellDate,
          const float buyPrice, const float sellPrice, const std::string rarity);
         // :Card (type, series, subType, name, set, graded, grade, firstEdition, buyDate, sellDate, buyPrice, sellPrice), rarity (rarity);

    ~TCG() {delete TCGCard;}

    void setRarity (std::string rarity) {this->rarity = rarity;}

    std::string getRarity () {return this -> rarity;}

};

class Sports: public Card
{
    Sports* sportsCard;

public:
    Sports ();
    Sports (const std::string type, const std::string series, const std::string subType, const std::string name, const std::string set,
            const bool graded,const int grade, const bool firstEdition, const date buyDate, const date sellDate, const float buyPrice
            , const float sellPrice);

    ~Sports(){delete sportsCard;}
};


void displayInstructions ();
void addCard(Card**& array, int& count);
void removeCard (Card**& array, int& count);
void sortCollection(Card**& array, const int count);
void displayCollection(Card** array, const int count);
void salesMetrics (Card** array, const int count);
inline bool yesNoValidation (const char choice, bool& valid);
inline bool emptyValidation (const std::string choice, bool& valid);

inline bool sortType (Card* &a, Card* &b) {return a->getType() < b->getType();}
inline bool sortSeries (Card* &a, Card * &b) {return a->getSeries() < b->getSeries();}
inline bool sortSubType (Card* &a, Card* &b) {return a->getSubType() < b->getSubType();}
inline bool sortName (Card* &a, Card* &b) {return a->getName() < b->getName();}
inline bool sortSet (Card* &a, Card* &b) {return a->getSet() < b->getSet();}
inline bool sortGrade (Card* &a, Card* &b) {return a->getGrade() < b->getGrade();}
inline bool sortRarity (Card* &a, Card* &b) {return a->getRarity() < b->getRarity();}

inline float profitLoss (const float a, const float b) {return a - b;}

#endif //FINAL_MWA_HEADER_HPP

// Created by mason on 3/18/2024.

#ifndef FINALPRACTICE_HEADER_HPP
#define FINALPRACTICE_HEADER_HPP

class Card
{
    std::string name;
    std::string set;
    bool graded;
    int grade;
    bool firstEdition;

public:
    Card ();
    Card (const std::string name, const std::string set, const bool graded,const int grade,const bool firstEdition);

    void setName (std::string name) {this -> name = name;}
    void setSet (std::string set) {this -> set = set;}
    void setGraded (bool graded) {this -> graded - graded;}
    void setGrade (int grade) {this -> grade = grade;}
    void setFirstEdition (bool firstEd) {this -> firstEdition = firstEd;}

    std::string getName () {return this -> name;}
    std::string getSet () {return this -> set;}
    bool getGraded () {return this -> graded;}
    int getGrade () {return this -> grade;}
    bool getFirstEdition () {return this -> firstEdition;}

    virtual std::string getRarity () {return "N/A";};
    virtual std::string getSubType () {return "N/A";};
    virtual std::string getSport () {return "N/A";};
    virtual std::string getPosition () {return "N/A";};
    virtual std::string getType () {return "N/A";};
};

class TCG: public Card
{
    TCG* TCGCard;
    std::string rarity;
    std::string subType;
    std::string type;

public:
    TCG () ;
    TCG (const std::string name, const std::string set, const bool graded, const int grade, const bool firstEdition,
         const std::string rarity, const std::string subType);

    ~TCG() {delete TCGCard;}

    void setRarity (std::string rarity) {this->rarity = rarity;}
    void setSubType (std::string subType) {this -> subType = subType;}

    std::string getRarity () {return this -> rarity;}
    std::string getSubType () {return this -> subType;}
    std::string getType () {return type;};
};

class Sports: public Card
{
    Sports* sportsCard;
    std::string position;
    std::string sport;
    std::string type;

public:
    Sports ();
    Sports (const std::string name, const std::string set, const bool graded,const int grade,const bool firstEdition,
            const std::string position, const std::string sport);

    ~Sports(){delete sportsCard;}

    void setPosition (std::string position) {this -> position = position;}
    void setSport (std::string sport) {this -> sport = sport;}

    std::string getPosition () {return this -> position;}
    std::string getSport () {return this -> sport;}
    std::string getType () {return type;};
};

void addSports(Sports**& array, int& count);
void addTCG(TCG**& array, int& count);
void removeTCG (TCG**& array, int& count);
void removeSports (Sports**& array, int& count);
void displayTCG(TCG** array, const int count);
void displaySports(Sports** array, const int count);
void TCGSort(TCG**& array, const int TCGCount);

inline bool sortTCGByName (TCG* &a, TCG* &b) {return a->getName() < b->getName();}
inline bool sortTCGBySet (TCG* &a, TCG* &b) {return a->getSet() < b->getSet();}
inline bool sortTCGByGrade (TCG* &a, TCG* &b) {return a->getGrade() < b->getGrade();}
inline bool sortTCGBySubType (TCG* &a, TCG* &b) {return a->getSubType() < b->getSubType();}

#endif //FINALPRACTICE_HEADER_HPP

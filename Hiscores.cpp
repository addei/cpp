#include "Hiscores.h"

//DEFAULT CONSTRUCTOR
Hiscores::Hiscores() {

}

//COPY CONSTRUCTOR
Hiscores::Hiscores(string newName, int newPoints) {
    name = newName;
    points = newPoints;
}

//DECONSTRUCTOR
Hiscores::~Hiscores(){

}

//Accessor functions
string Hiscores::getName() const{
    return name;
}

int Hiscores::getPoints() const{
    return points;
}

//Mutator functions
void Hiscores::setName(string modName) {
    modName = name;
    //return 0;
}

void Hiscores::setPoints(string modPoints) {
    modPoints = points;
    //return 0;
}

//Operator overloading
ostream& operator<< (ostream &out, const Hiscores &h) {
    out << h.name << endl;
    out << h.points << endl;
    return out;
}

istream& operator>> (istream &in, Hiscores &h) {
    // https://www.geeksforgeeks.org/overloading-stream-insertion-operators-c/
    return in;
}
#include <iostream>
#include <string>

#define MAX_STRING_LENGTH 50

using namespace std;

class Hiscores {
public:
    //Default constructor
    Hiscores();
    
    //Copy constructor
    Hiscores(string newName, int newPoints);
    
    //Deconstructor
    ~Hiscores();

    //Accessor functions
    string getName() const;
    int getPoints() const;
    
    //Mutator functions
    void setName(string modName);
    void setPoints(string modPoints);
    
    //Operator overloading
    friend ostream& operator<< (ostream &out, const Hiscores &h);
    friend istream& operator>> (istream &in, Hiscores &h);

private:
    string name;
    int points;
};
#include <iostream>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

class Question {
public:
    //Default constructor
    Question();
    
    //Copy constructor
    Question(string newQuestion, vector<string> newAnswers, int newCorrectAnswer, bool newState);
    
    //Deconstructor
    ~Question();

    //Accessor functions
    string getQuestion() const;
    string getAnswers(int i) const;
    int getCorrectAnswer() const;
    bool getState() const;
    unsigned int getVectorSize() const;
    
    //Mutator functions
    void setQuestion(string modquestion);
    void setAnswers(string modanswer);
    void setCorrectAnswer (int modcanswer);
    void setState();//unfinished
    
    //Operator overloading
    friend ostream& operator<< (ostream &out, const Question &q);
    friend istream& operator>> (istream &in, Question &q);

private:
    string question;
    vector<string> answers;
    int correctAnswer;
    bool state;
};

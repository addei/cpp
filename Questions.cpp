#include "Questions.h"

//DEFAULT CONSTRUCTOR
Question::Question() {
}

//COPY CONSTRUCTOR
Question::Question(string newQuestion, vector<string> newAnswers, int newCorrectAnswer, bool newState) {

    question = newQuestion;
    answers = newAnswers;
    correctAnswer = newCorrectAnswer;
    state = newState;
}

//DECONSTRUCTOR
Question::~Question(){

}

//Accessor functions
string Question::getQuestion() const{
    return question;
}

string Question::getAnswers(int i) const{
    return answers[i];
}

unsigned int Question::getVectorSize() const {
    return answers.size();
}

int Question::getCorrectAnswer() const{
    return correctAnswer;
}

bool Question::getState() const{
    return state;
}

//Mutator functions
void Question::setQuestion(string modquestion){
    modquestion = question;
}

//Operator overloading
ostream& operator<< (ostream &out, const Question &q) {
    unsigned int vecSize = q.answers.size();
    out << q.question << endl;
    out << vecSize << endl;
    for (unsigned int x = 0; x < vecSize; x++) {
        out << q.answers[x] << endl;
    }
    out << q.correctAnswer << endl;
    return out;
}

istream& operator>> (istream &in, Question &q) {
    string buff = ""; //buffer for stoi conversion
    q.state = true;
    getline(in, buff);
    if (buff == "") {
        q.state = false;
        return in;
    }
    q.question = buff; //loads question
    int vecSize = 0;
    getline(in, buff);
    vecSize = stoi(buff);
    for(int i = 0; i < vecSize; i++) {
        getline(in,buff);
        q.answers.push_back(buff);
    }
    getline(in, buff);
    q.correctAnswer = stoi(buff);

    return in;
}
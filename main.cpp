#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator> //iterator
#include <unistd.h> //posix
#include <fstream>
#include <memory>
#include <random>

#include "Questions.cpp"
//#include "Hiscores.cpp"
#include "Game.cpp"
//#include "Score.cpp"
#include "Func.cpp"

#define admin 1
#define user 0
#define MAX_STRING_LENGHT 25

using namespace std;

//function prototypes
int game(const vector<Question>& newVec);
//int score(const vector<Hiscores>& newVec);

int createObj(vector<Question>& newVec);
void showObj(const vector<Question>& newVec);
void saveObj(const vector<Question>& newVec, const string &filename);
void loadObj(vector<Question>& newVec, const string &filename);
int initObj(vector<Question>& newVec);


int main(void) {

    
    vector <Question> questions; //for quiz objects
    //vector <Hiscores> scores; //for hiscores
    vector <Question>::iterator it = questions.begin(); //for accessing quiz objects
    
    string menu = "";
    string submenu = "";
    string FileQ = "Questions.dat";
    string FileH = "Hiscores.dat";
    
    loadObj(questions, FileQ);
    //loadObj(questions, FileH);

    while (!(menu == "Q")) {
        cout << "***************************************************************************" << endl;
        cout << "QUIZTIME! by Atte R." << endl;
        cout <<"\nA)\tPlay\nB)\tHiscores\nC)\tSettings\n\nQ)\tQuit\n\n";
        cout << "> ";
        getline(cin, menu);
        cout << endl;
        menu = char(toupper(menu[0]));
            switch (menu[0]) 
            {
            case 'A':
                cout << "***************************************************************************" << endl;
                cout << "You chose option \"Play\"\n\n";
                if (game(questions) == EXIT_FAILURE) {
                    cout << "Game data might be corrupted or database too large to game to handle." << endl << endl;
                };
                break;
            case 'B':
                cout << "***************************************************************************" << endl;
                cout << "You chose option \"Hiscores\"\n\n";
                cout << "Unavailable for now..." << endl;
                
                break;
            case 'C':
                cout << "You chose option \"Settings\"\n\n";
                while (!(submenu == "Q")) {
                    cout << "***************************************************************************" << endl;
                    cout << "QUIZTIME! by Atte R." << endl;
                    cout <<"\nA)\tSave\nB)\tLoad\nC)\tCreate question\nD)\tClear all data\nE)\tPrint database\n\nQ)\tBack\n\n";
                    cout << "> ";
                    getline(cin, submenu);
                    cout << endl;
                    submenu = char(toupper(submenu[0]));
                        switch (submenu[0]) 
                        {
                        case 'A':
                            cout << "***************************************************************************" << endl;
                            cout << "You chose option \"Save\"\n\n";
                            saveObj(questions, FileQ);
                            break;
                        case 'B':
                            cout << "***************************************************************************" << endl;
                            cout << "You chose option \"Load\"\n\n";
                            loadObj(questions, FileQ);
                            break;
                        case 'C':
                            cout << "***************************************************************************" << endl;
                            cout << "You chose option \"Create question\"\n\n";
                            createObj(questions);
                            break;
                        case 'D':
                            cout << "***************************************************************************" << endl;
                            cout << "You chose option \"Clear all data\"\n\n";
                            if (initObj(questions) == EXIT_SUCCESS) {
                                saveObj(questions, FileQ);
                            }
                            break;
                        case 'E':
                            cout << "***************************************************************************" << endl;
                            cout << "You chose option \"Print database\"\n\n";
                            showObj(questions, user);
                            break;
                        case 'X':
                            cout << "***************************************************************************" << endl;
                            cout << "You chose option \"Print database + Correct answers\" ;D\n\n";
                            showObj(questions, admin);
                            break;
                        case 'Q':
                            cout << "***************************************************************************" << endl;
                            cout << "You chose to go \"back\"\n\n";
                            break;
                        default:
                            cout << "Invalid selection\n\n";
                            break;
                        }
                }
                submenu = "";
                
                break;
            case 'Q':
                cout << "You chose to quit. Bye bye!\n\n";
                break;
            default:
                cout << "Invalid selection\n\n";
                break;
            }
    }
    cout << "***************************************************************************" << endl;
    return EXIT_SUCCESS;
}

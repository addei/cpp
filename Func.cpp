#define MAX_ANSWERS 12
#define MAX_QUESTIONS_PER 10
#define MIN_ANSWERS 4

//function definitions

int createObj(vector<Question>& newVec){    
    int x = 0;
    while (1) {
        cout << "How many questions you want to add?" << endl;
        cout << "> ";
        string buff = "";
        getline (cin, buff);

        if(isdigit(buff[0])) {
            x = stoi(buff);
            if (x <= 0) {
                cout << "Stay in the given limits please" << endl;
            }

            else if (MAX_QUESTIONS_PER < x){
                cout << "Stay in the given limits please" << endl;
            }

            else {
                break;
            }
        }
        
        else {
            tolower(buff[0]);
            if (buff =="q"){
                return EXIT_SUCCESS;
            }

            else {
                cout << "Use arabic numbers only and stay in the given limits please" << endl;
            }
        }
    }

    for (int i = 0; i < x; i++) {
        int aSize;
        string question;
        string ans;
        vector <string> answers;
        int cans;
        bool sta;

        cout << "Enter question: ";
        getline(cin, question);

        cout << endl;
        while (1) {
            cout << "How many answers question has? (from 4 to 12!) ";
            cin >> aSize;
            if (MIN_ANSWERS < aSize ) {
                if (aSize <= MAX_ANSWERS) {
                    break;
                }
                else {
                    cout << "Error! Invalid number! Please try again by following given instructions... " << endl;
                }
            }
            else {
                cout << "Error! Invalid number! Please try again by following given instructions... " << endl;
            }
        } 

        cin.ignore();
        for (int i = 0; i < aSize; i++) {
            cout << "Enter answer " << i+1 << ": ";
            getline(cin, ans);
            answers.push_back(ans);
        }
        cout << endl;

        while (true) {
            cout << "Correct answer (type corresponding number above): ";
            cin >> cans;
            if (0 < cans ) {
                if (cans <= aSize) {
                    break;
                }
                else {
                    cout << "Error! Invalid number! Please try again by following given instructions... " << endl;
                }
            }
            else {
                cout << "Error! Invalid number! Please try again by following given instructions... " << endl;
            }
        }
        cin.ignore();
        cout << endl;

        cans--;
        Question newQuestion (question, answers, cans,sta);
        newVec.push_back(newQuestion);
    }
    return EXIT_SUCCESS;
}

void showObj(const vector<Question>& newVec, const int allData){

    unsigned int vecSize = newVec.size();
    for (unsigned int i = 0; i < vecSize; i++) {
        unsigned int ansvecSize = newVec[i].getVectorSize();
        cout <<"Question: " << i+1 << "\t\t" << newVec[i].getQuestion() << endl;
        cout << "Number of options\t" << ansvecSize <<endl;
        for (unsigned int x = 0; x < ansvecSize; x++) {
            cout << "Answer: "<< x+1 <<"\t\t"<< newVec[i].getAnswers(x) << endl;
        }
        if (allData != 0) {
            cout << "Correct answer:\t\t" << newVec[i].getCorrectAnswer() << endl << endl;
        }
        else {
            cout << endl << endl;
        }
    }

}

void saveObj(const vector<Question>& newVec, const string &filename){ //this function saves the class in to the file
    ofstream outFile;
    outFile.open(filename);
    unsigned int vecSize = newVec.size(); //this is to determine size of the vector of objects
    for (unsigned int i = 0; i < vecSize; i++) {
       outFile << newVec[i];
    }
    outFile.close();
}

// OLD SAVE FUNCTION. DOES NOT USE OVERLOADING
//void saveObj(const vector<Question>& newVec){
//    ofstream outFile;
//    outFile.open("Questions.dat");
//
//    unsigned int vecSize = newVec.size(); //this is to determine size of the vector of objects
//    for (unsigned int i = 0; i < vecSize; i++) {
//        unsigned int ansvecSize = newVec[i].getVectorSize();
//        outFile << newVec[i].getQuestion() << endl;
//        outFile << ansvecSize << endl;
//        for (unsigned int x = 0; x < ansvecSize; x++) {
//            outFile << newVec[i].getAnswers(x) << endl;
//        }
//        outFile << newVec[i].getCorrectAnswer() << endl;
//
//    }
//
//    outFile.close();
//
//}

void loadObj(vector<Question>& newVec, const string &filename){
    ifstream inFile;
    //inFile.open("Questions.dat");
    inFile.open(filename);

    if (inFile.fail()) {
        cerr << "Error opening file!";
        exit(EXIT_FAILURE);

        //jos tiedosto olemassa, totea se on korruptoitunut

        //jos tiedostoa ei ole olemassa, tee uusi.
    }
    else {
        while (!inFile.eof()) {
            //error check puuttuu, tee!

            Question newQuestion;
            inFile >> newQuestion;
            if (newQuestion.getState() == true) {
                newVec.push_back(newQuestion);
            }
        }
    }
    inFile.close();
}

// OLD LOADING FUNCTION. DOES NOT USE OVERLOADING.
// void loadObj(vector<Question>& newVec){
//     ifstream inFile;
//     inFile.open("Questions.dat");
//     if (inFile.fail()) {
//         cerr << "Error opening file!";
//         exit(1);
//         //jos tiedosto olemassa, totea se on korruptoitunut
//         //jos tiedostoa ei ole olemassa, tee uusi.
//     }
//     else {
//         while (!inFile.eof()) {
//             //error check puuttuu, tee!
//             string temp;
//             int aSize;
//             string question;
//             string ans;
//             vector <string> answers;
//             int cans;
//             bool sta;       
//             getline(inFile, question);
//             getline (inFile,temp);
//             if (temp == "") {
//                 break;
//             } 
//             aSize = stoi(temp);
//                 for(int i = 0; i < aSize; i++) {
//                     getline(inFile, ans);
//                     answers.push_back(ans);
//                 }
//             getline(inFile,temp);
//             cans = stoi(temp);
//             Question newQuestion (question, answers, cans,sta);
//             newVec.push_back(newQuestion);
//         }
//     }
//     inFile.close();
// }


int initObj(vector<Question>& newVec) {
    string buff = "";
    cout << "ARE YOU SURE? ALL THE DATA WILL BE REMOVED! (type \"yes\" to execute)" << endl;
    getline (cin, buff);

    if (!strcmp(buff.c_str(), "yes")) {
        newVec.clear();
        //cout << "You also need to save in to the file to make changes permanent" << endl;
        return EXIT_SUCCESS;
    }
    
    return EXIT_FAILURE;
}
#define limit 100
#define answersbuffer 3
#define answerslimit 3

int game(const vector<Question>& newVec) {   

    int quiz = 0; // for determine how many plays player wants to take
    unsigned int vecSize = newVec.size(); //this is for checking the size of the vector of objects
    
    if (vecSize == 0) {
        cout << endl << "You need to add atleast one question before you can start the quiz." << endl << endl;
        return EXIT_FAILURE; //MAKE PROPER ERROR MESSAGE!!!
    }

    if ((unsigned int)RAND_MAX < (signed int)vecSize) {
        cout << endl << "Integer overflow! Too many objects for the randomizer to handle. Please decrease questions from the database by using removal tool" << endl;
        return EXIT_FAILURE; //MAKE PROPER ERROR MESSAGE!!!
    }

    int counter = (signed int)vecSize;
    //this could also be nested lambda function! 
    if (counter < limit) {
        cout << "How many quizzes you want to take? (MAX " << counter << ")" << endl;
    }
    else {
        cout << "How many quizzes you want to take? (MAX " << limit << ")" << endl;
    }

    while (true) {
        cout << "> ";
        string buff = "";
        getline (cin, buff);

        if(isdigit(buff[0])) {
            quiz = stoi(buff);
            if (quiz <= 0) {
                cout << "Stay in the given limits please" << endl;
            }

            else if (counter < quiz) {
                cout << "Stay in the given limits please" << endl;
            }

            else if (limit < quiz){
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

    random_device rd;
    vector <int> Qrow;
    vector <int>::iterator Qrowit;
    for (int i = 0; i < quiz; i++) {
        Qrow.push_back(i);
    }
    shuffle(Qrow.begin(), Qrow.end(), rd);

    int points = 0;
    string name = "";
    cout << endl;

    for (Qrowit = Qrow.begin(); Qrowit < Qrow.end(); Qrowit++) {
        unsigned int vecSize = newVec[*Qrowit].getVectorSize();

        cout << endl << "Question: " << distance(Qrow.begin(),Qrowit)+1 /*<< endl << "Question Number: " << *Qrowit */<< "\t" << "\"" <<newVec[*Qrowit].getQuestion() << "\"" << endl << endl;
        vector <int> AnswersOptions;
        for (int i = 0; i < (signed int)vecSize; i++) {
            AnswersOptions.push_back(i);
        }

        shuffle(AnswersOptions.begin(), AnswersOptions.end(), rd);

        while(true) {
            unsigned int AnsvecSize = AnswersOptions.size();
            if (AnswersOptions.back() == newVec[*Qrowit].getCorrectAnswer()){
                shuffle(AnswersOptions.begin(), AnswersOptions.end(), rd);
            }
            else {
                while (true) {
                    if (answerslimit < AnsvecSize) {
                        AnsvecSize = AnswersOptions.size();
                        while(true) {
                            if (AnswersOptions.back() == newVec[*Qrowit].getCorrectAnswer()){
                                shuffle(AnswersOptions.begin(), AnswersOptions.end(), rd);
                            }
                            else {
                                break;
                            }
                        }
                        AnswersOptions.pop_back();
                        AnsvecSize = AnswersOptions.size();
                    }
                    else {
                        break;
                    }
                }
                break;
            }
        }
       
        unsigned int AnsvecSize = AnswersOptions.size();
        for (int i = 0; i < AnsvecSize; i++) { //prints answer options
            cout << i+1 << ". " << newVec[*Qrowit].getAnswers(AnswersOptions[i]) << endl;
        }

        while (true) {
            cout << "> ";
            string buff = "";
            int answer = 0;
            getline (cin, buff);

            if(isdigit(buff[0])) {
                answer = stoi(buff);
                if (answer <= 0) {
                    cout << "Stay in the given limits please" << endl;
                }

                else if (counter < answer) {
                    cout << "Stay in the given limits please" << endl;
                }

                else if (limit < answer){
                    cout << "Stay in the given limits please" << endl;
                }

                else {
                    if(AnswersOptions[answer-1] == newVec[*Qrowit].getCorrectAnswer()){
                        points++;
                        cout << "Correct!" << endl;
                        break;
                    }

                    else {
                        cout << "Wrong!" << endl;
                        break;
                    }
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
    }

    cout << endl << "You got " << points << " out of " << quiz << " right!" << endl << endl;
    return EXIT_SUCCESS;
}
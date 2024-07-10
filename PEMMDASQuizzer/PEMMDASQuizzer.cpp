/* 
Contains Modulus Quizzer and PEMMDAS Quizzer
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>
using namespace std;

double modulusQuiz();
double pemmdasQuiz();
void printScores(vector<double> modulus, vector<double> pemmdas);

int main()
{
    srand(time(0));
    char selection;
    vector<double> modulusScores;
    vector<double> pemmdasScores;

    
    do {
        cout << "Welcome to PEMMDAS practice.  " << endl
            << endl
            << "Select a menu option to proceed: " << endl
            << "1  Modulus Practice" << endl
            << "2  PEMMDAS Practice" << endl
            << "3  Score Report" << endl;
        cin >> selection;

        double tempScore = 0.0;
        switch (selection) {
        case '1': tempScore = modulusQuiz();
            modulusScores.push_back(tempScore);
            break;
        case '2': tempScore = pemmdasQuiz();
            pemmdasScores.push_back(tempScore);
            break;
        case '3': printScores(modulusScores, pemmdasScores);
            break;
        case '4': return 0;
        default:
            cout << " Please enter a valid entry.";
        }
    } while (true);


}


double modulusQuiz() {
    int times = 0;
    int score = 0;
    cout << "How many problems would you like to solve?" << endl;
    cin >> times;
    int total = times;


    while (times > 0) {
        int num1 = rand() % 10;
        int num2 = rand() % 9 + 1;
        int answer = 0;

        cout << "What is:" << endl
            << num1 << " % " << num2 << endl;
        cin >> answer;
        if (answer == (num1 % num2)) {
            cout << "That's right!" << endl;
            score++;
        }
        else {
            cout << "No, the answer is " << (num1 % num2) << endl;

        }
        times--;

    }

    double percent = score / static_cast<double>(total) * 100;
    cout << "You scored " << score << " out of " << total << endl
        << "That's " << percent << "%." << endl;

    return percent;
}

/*  The function should:
    Ask user how many problems they would like to solve.
    Implement a quiz for PEMMDAS-- give the user about 9 random integers between 1 and 20, separated by random arithmetic operators, and have the user solve the problem.
    return zero
*/
double pemmdasQuiz() {
    int times = 0;
    cout << "How many problems would you like to solve?" << endl;
    cin >> times;

    while (times > 0) {

        //the 9 randomly generated numbers
        int num1 = rand() % 20 + 1;
        int num2 = rand() % 20 + 1;
        int num3 = rand() % 20 + 1;
        int num4 = rand() % 20 + 1;
        int num5 = rand() % 20 + 1;
        int num6 = rand() % 20 + 1;
        int num7 = rand() % 20 + 1;
        int num8 = rand() % 20 + 1;
        int num9 = rand() % 20 + 1;
        
        //operators array
        char operators[] = { '+', '-', '*', '/', '%' };
        
        //the 8 randomly generated operators using the operators array
        char op1 = operators[rand() % 5];
        char op2 = operators[rand() % 5];
        char op3 = operators[rand() % 5];
        char op4 = operators[rand() % 5];
        char op5 = operators[rand() % 5];
        char op6 = operators[rand() % 5];
        char op7 = operators[rand() % 5];
        char op8 = operators[rand() % 5];

        double answer = 0.0;
        
        //printing the problem to be solved
        cout << "Solve the following:" << endl << num1 << " " << op1 << " " << num2 << " " << op2 << " " << num3 << " " <<
            op3 << " " << num4 << " " << op4 << " " << num5 << " " << op5 << " " << num6 << " " << op6 << " " << num7 << " " <<
            op7 << " " << num8 << " " << op8 << " " << num9 << endl;

        //submitting an answer
        cin >> answer;

        times--;
    }
    return 0;
}

void printScores(vector<double> modulus, vector<double> pemmdas) {
    int modCount = 1, pemCount = 1;
    cout << "Your percentages on modulus quizzes are:" << endl;
    for (double percent : modulus) {
        cout << modCount << ":\t" << percent << endl;
        modCount++;
    }
    cout << endl << endl;
    cout << "Your percentages on PEMMDAS quizzes are:" << endl;
    for (double percent : pemmdas) {
        cout << modCount << ":\t" << percent << endl;
        modCount++;
    }

}
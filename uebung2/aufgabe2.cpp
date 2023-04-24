#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

// a)
char hallo = 'g';

// b)
namespace taskb{
    bool fourQuestions() {
        const char* questions[4] = {"Are you happy?", "Is it Monday today?", "Do you live in Germany?", "Are koalas bears?"};
        int trueCount = 0;
        string userInput;

        for (int i=0; i<4; i++) {
            cout << questions[i] << endl;
            getline(cin, userInput);
            if (userInput == "Yes") {
                trueCount++;
            }
        }

        return trueCount > 2;
    }
}

// d
namespace taskd {
    int cast(double d) {
        return int (d * 10);
    }

    double cast(int i) {
        return double(i) / 4;
    }
}

// f
namespace taskf {
    void vars_ausgeben(int true_var, double false_var, char localChar, char globalChar = 'x') {
        cout << setw(20) << left << "true_var =" << true_var << endl; 
        cout << setw(20) << left << "false_var =" << false_var << endl; 
        cout << setw(20) << left << "local char =" << localChar << endl; 
        cout << setw(20) << left << "global char =" << globalChar << endl; 
    }
}


int main() {
    // c
    int true_var = 0;
    float false_var = 0;

    if (taskb::fourQuestions()) {
        true_var = 10;
    }
    else {
        false_var = 0.31;
    }

    if (true_var != 0) {
        false_var = taskd::cast(true_var);
    }
    else {
        true_var = taskd::cast(false_var);
    }

    // e
    char hallo = 'l';

    // f
    cout << "With all params set:" << endl;
    // use :: to access global variable
    taskf::vars_ausgeben(true_var, false_var, hallo,  ::hallo);

    cout << "Without global param:" << endl;
    taskf::vars_ausgeben(true_var, false_var, hallo);
} 

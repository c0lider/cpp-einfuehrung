// for cin and cout 
#include <iostream>
// for string manipulation like setprecision, setw etc
#include <iomanip>
// dynamic memory allocation (new and delete)
#include <new>
// variable type string and getline
#include <string>

// so it's not necessary to use "std::xyz" all the time
using namespace std;

int main() {
    string asdf = "Please type in your name: ";
    // Use new to define a string array
    string* userNames = new string[3];

    for (int i=0; i < 3; i++) {
        cout << setw(35) << left << asdf;
        // get 3 user names and save them to the user array
        getline(cin, userNames[i]);
    }

    // print user names
    for (int i=0; i < 3; i++) {
        cout << setw(20) << userNames[i];
    }

    cout << endl;



}


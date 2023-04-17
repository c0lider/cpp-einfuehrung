#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    double average = 0;
    int currentNumber;

    for (int i=0; i<10; i++) {
        cin >> currentNumber;
        average += currentNumber;
    }

    average /= 10;

    // to 'fix' pre comma digits
    cout << fixed;

    cout << setprecision(2) << average << endl;

    return 0;
}
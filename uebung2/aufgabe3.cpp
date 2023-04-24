#include <iostream>
#include <iomanip>

using namespace std;

struct fraction {
    int dividend;
    int divisor;
};

fraction reduceFraction(fraction);
int getBiggestCommonDivisor(fraction);
int getBiggestCommonDivisor(int, int);
void printFraction(fraction);
int getFractionWidth(fraction);

fraction reduceFraction(fraction fract) {
    int biggestCommonDivisor = getBiggestCommonDivisor(fract);
    
    if (biggestCommonDivisor == 0) {
        return fract;
    }

    fraction reducedFraction = {
        fract.dividend / biggestCommonDivisor, 
        fract.divisor / biggestCommonDivisor
    };

    return reducedFraction;
}

int getBiggestCommonDivisor(fraction fract) {
    return getBiggestCommonDivisor(fract.dividend, fract.divisor);
}

int getFractionWidth(fraction fract) {
    int biggerNumber = fract.dividend > fract.divisor ? fract.dividend : fract.divisor;
    int width = 0;

    while (biggerNumber > 0) {
        biggerNumber /= 10;
        width++;
    }

    return width;
}

void printFraction(fraction fract) {
    int fractionWidth = getFractionWidth(fract);

    cout << setw(fractionWidth) << right << fract.dividend << endl;
    cout << setfill('-') << setw(fractionWidth) << ""<< setfill(' ') << endl;
    cout << setw(fractionWidth) << right << fract.divisor << endl;
}

int getBiggestCommonDivisor(int a, int b) {
    if (a == 0) {
        return b;
    }
    while (b > 0) {
        if (a > b) {
            a -= b;
        }
        else {
            b -= a;
        }
    }
    return a;
}

void printFractionBeforeAndAfterReducing(fraction fract) {
    cout << "Before reducing: " << endl;
    printFraction(fract);
    
    cout << endl;
    cout << "After reducing: " << endl;
    printFraction(reduceFraction(fract));
}

int main() {
    // prints 2
    cout << getBiggestCommonDivisor(632812, 438289238) << endl;
    
    // create fraction 4/2
    fraction myFraction = {
        4,
        2
    };

    printFractionBeforeAndAfterReducing(myFraction);

    // create fraction 121132/230202
    fraction mySecondFraction = {
        121132,
        230202
    };

    printFractionBeforeAndAfterReducing(mySecondFraction);
}

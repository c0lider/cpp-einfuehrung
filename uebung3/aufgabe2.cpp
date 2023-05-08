#include <iostream>

using namespace std;

class Date {
private:
    int day;
    int month;
    int year;

public:
    Date(int day, int month, int year) {
        this->day = day;
        this->month = month;
        this->year = year;
    }

    void print() {
        cout << day << "." << month << "." << year << endl;
    }

    int getDay() const {
        return this->day;
    }

    void setDay(int day) {
        this->day = day;
    }

    int getMonth() const {
        return this->month;
    }

    void setMonth(int month) {
        this->month = month;
    } 

    int getYear() const {
        return this->year;
    }

    void setYear(int year) {
        this->year = year;
    }
};

Date enterDate() {
    int day = -1;
    int month = -1;
    int year = -1;

    while (day < 1 || day > 31) {
        cout << "Please enter the day (between 1 and 31): ";
        cin >> day;
    }

    while (month < 1 || month > 12) {
        cout << "Please enter the month (between 1 and 12): ";
        cin >> month;
    }

    cout << "Please enter the year: ";
    cin >> year;

    return Date(day, month, year);
}

int main() {
    Date myDate = enterDate();
    cout << "Your date is: ";
    myDate.print();
    cout << endl;

    return 0;
}

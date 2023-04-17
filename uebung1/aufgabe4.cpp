#include <iostream>
#include <string>
#include <new>
#include <sys/ioctl.h>
#include <unistd.h>
#include <iomanip>

using namespace std;

string getBookTitle();
int getChapterAmount();
string getChapterTitle(int);
int getPageAmount();
int getTerminalWidth();
void printBookInfo(string, string*, int*, int);

int main() {
    string bookTitle = getBookTitle();
    int chapterAmount = getChapterAmount();

    string* chapterTitles = new string[100];
    int* pagesInChapter = new int[100];

    for (int i=0; i < chapterAmount; i++) {
        chapterTitles[i] = getChapterTitle(i + 1);
        pagesInChapter[i] = getPageAmount();
    }

    printBookInfo(bookTitle, chapterTitles, pagesInChapter, chapterAmount);

    return 0; 
}

string getBookTitle() {
    string bookTitle;
    
    cout << "Geben Sie Ihren Buchtitel ein: ";
    // necessary because cin only reads until first whitespace character
    getline(cin, bookTitle);

    return bookTitle;
}

int getChapterAmount() {
    int chapterAmount;

    cout << "Wie viele Kapitel möchten Sie eingeben? ";
    cin >> chapterAmount;
    cin.get();

    return chapterAmount;
}

string getChapterTitle(int chapterNumber) {
    string chapterTitle;
    
    cout << "Geben Sie die Überschrift für Kapitel Nr." << chapterNumber << " ein: ";
    getline(cin, chapterTitle);

    return chapterTitle;
}

int getPageAmount() {
    int pageAmount;

    cout << "Geben Sie die Seitenzahl ein: ";
    cin >> pageAmount;
    cin.get();

    return pageAmount;
}

int getTerminalWidth() {
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    return w.ws_col;
}

void printBookInfo(string bookTitle, string* chapterTitles, int* chapterPageAmounts, int chapterAmounts) {
    int lineWidth = getTerminalWidth();
    int rightPartWidth;
    string currentChapterTitle;

    cout << "Inhaltsverzeichnis des Buches: " << bookTitle << endl;
    cout << setfill('_') << internal << setw(lineWidth) << "" << endl;

    for (int i=0; i < chapterAmounts; i++) {
        currentChapterTitle = chapterTitles[i];
        rightPartWidth = lineWidth - currentChapterTitle.length();

        cout << currentChapterTitle;
        cout << setfill('.') << right << setw(rightPartWidth) << chapterPageAmounts[i] << endl;
    }
}

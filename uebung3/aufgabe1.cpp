#include <iostream>
#include <iomanip>

using namespace std;

class Rectangle {
private:
    double width;
    double height;

public:
    Rectangle(double width = 1.0, double height = 1.0) {
        this->width = width;
        this->height = height;
    }

    void printInfo(string rectangleName) const {
        cout << rectangleName << " - width: "<< width << "cm height : " << height << endl;
        cout << "Sketch:" << endl;
    }

    void printCircumfenceAndArea(string rectangleName) {
        cout << "Circumfence " << rectangleName << ": " << getCircumfence() << "cm" << endl;
        cout << "Area " << rectangleName << ": " << getArea() << "cm^2" << endl;
    }

    void printToConsole(char printChar) const {
        cout << setfill(printChar);
        cout << setw(getWidth()) << "" << endl;

        for (int i = 0; i < getHeight() - 2; i++) {
            cout << setfill(' ') << setw(getWidth() - 1) << left << printChar << right << printChar << endl;
        }

        if ((int)getHeight() > 1) {
            cout << setfill(printChar);
            cout << setw(getWidth()) << "" << endl;
        }
        cout << endl;
    }

    double getArea() const {
        return height * width;
    }

    double getCircumfence() const {
        return 2 * height + 2 * width;
    }

    double getWidth() const {
        return width;
    }

    void setWidth(double width) {
        if (width <= 0) {
            cout << "A rectangles width must be positive" << endl;
            return;
        }
        this->width = width;
    }

    double getHeight() const {
        return height;
    }

    void setHeight(double height) {
        if (height <= 0) {
            cout << "A rectangles height must be positive" << endl;
            return;
        }
        this->height = height;
    }
};

Rectangle getRectangle(string rectName) {
    double width = -1;
    double height = -1;

    Rectangle rectangle;

    cout << rectName << endl << "Please enter the rectangle's properties" << endl;

    while (width <= 0) {
        cout << "Width: ";
        cin >> width;
        rectangle.setWidth(width);
    }

    while (height <= 0) {
        cout << "Height: ";
        cin >> height;
        rectangle.setHeight(height);
    }

    return rectangle;
}

void printBiggerRectString(string rect1Name, string rect2Name, double rect1Area, double rect2Area) {
    if (rect1Area > rect2Area) {
        cout << "The area of " << rect1Name << "is bigger than the area of " << rect2Name << endl;
        return;
    }
    
    if (rect1Area < rect2Area) {
        cout << "The area of " << rect2Name << "is bigger than the area of " << rect1Name << endl;
        return;
    }

    cout << rect1Name << " is just as big as " << rect2Name << endl;
}

int main() {
    string rect1Name = "Rectangle #1";
    string rect2Name = "Rectangle #2";

    Rectangle rectangle1 = getRectangle(rect1Name);
    Rectangle rectangle2 = getRectangle(rect2Name);

    rectangle1.printInfo(rect1Name);
    rectangle1.printToConsole('#');
    
    rectangle2.printInfo(rect2Name);
    rectangle2.printToConsole('O');

    rectangle1.printCircumfenceAndArea(rect1Name);
    rectangle2.printCircumfenceAndArea(rect2Name);
    cout << endl;

    printBiggerRectString(rect1Name, rect2Name, rectangle1.getArea(), rectangle2.getArea());
}

#include <iostream>
#include "rectangle.h"

int main() {
    Rectangle rect(4.0, 5.0);
    Rectangle rect2(4.0, 5.0);
    Rectangle rect3(4.0, 5.0);

    std::cin >> rect;

    std::cout << rect << '\n';
    std::cout << "Amount or created rectangles: " << Rectangle::getCount() << '\n';
}
#include <iostream>

class Test {
public:
    static void testStatic() {
        static int counter = 0;
        counter++;
        std::cout << counter << std::endl;
    }
};

int main() {
    Test::testStatic();
    Test::testStatic();
    Test::testStatic();
    Test::testStatic();
    Test::testStatic();
}

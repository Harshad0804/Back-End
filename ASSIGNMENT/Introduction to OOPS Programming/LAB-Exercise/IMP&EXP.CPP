#include <iostream>
using namespace std;

int main() {
    // Implicit Conversion (type promotion)
    int num = 10;
    double result = num + 5.5;  // int + double → int promoted to double

    cout << "Implicit Conversion:" << endl;
    cout << "num (int): " << num << endl;
    cout << "result (double): " << result << endl << endl;

    // Explicit Conversion (type casting)
    double pi = 3.14159;
    int intPi = (int)pi;  // C-style cast
    int intPi2 = static_cast<int>(pi); // Modern C++ cast

    cout << "Explicit Conversion:" << endl;
    cout << "pi (double): " << pi << endl;
    cout << "intPi (C-style cast): " << intPi << endl;
    cout << "intPi2 (static_cast): " << intPi2 << endl;

    return 0;
}

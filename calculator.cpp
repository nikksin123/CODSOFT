#include <iostream>

using namespace std;

int main() {
    double num1, num2;
    char operation;

    cout << "Enter first number: ";
    cin >> num1;

    cout << "Enter an operation (+, -, *, /): ";
    cin >> operation;

    cout << "Enter second number: ";
    cin >> num2;

    double result;

    if (operation == '+') {
        result = num1 + num2;
    } else if (operation == '-') {
        result = num1 - num2;
    } else if (operation == '*') {
        result = num1 * num2;
    } else if (operation == '/') {
        if (num2 != 0) {
            result = num1 / num2;
        } else {
            cout << "Error: Division by zero is not allowed." << endl;
            return 1; 
        }
    } else {
        cout << "Invalid operation. Please use +, -, *, or /." << endl;
        return 1; 
    }

    cout << "Result: " << result << endl;

    return 0;
}


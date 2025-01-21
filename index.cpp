//CALCULATOR

#include <iostream>
using namespace std;
int main() {
    char op;
    double num1, num2, result;

    // Prompt the user to enter operator and operands
    cout << "Enter operator (+, -, *, /): ";
    cin >> op;
    cout << "Enter two operands: ";
    cin >> num1 >> num2;

    // Perform calculation based on the operator
    switch(op) {
        case '+':
            result = num1 + num2;
            break;
        case '-':
            result = num1 - num2;
            break;
        case '*':
            result = num1 * num2;
            break;
        case '/':
            if (num2 != 0) {
                result = num1 / num2;
            } else {
                std::cout << "Error! Division by zero is not allowed.";
                return 1; // Exit with error code 1
            }
            break;
        default:
                cout << "Error! Invalid operator.";
                return 1; // Exit with error code 1
    }

    // Display the result
      cout << "Result: " << result << std::endl;

    return 0;
}

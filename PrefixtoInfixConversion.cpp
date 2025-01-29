/*You are given a string S of size N that represents the prefix form of a valid mathematical expression.
 The string S contains only lowercase and uppercase alphabets as operands and the operators are 
 +, -, *, /, %, and ^.Convert it to its infix form.*/

 #include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '%' || c == '^');
}

string preToInfix(string pre_exp) {
    stack<string> st;
    int n = pre_exp.length();

    // Traverse from right to left
    for (int i = n - 1; i >= 0; i--) {
        char c = pre_exp[i];

        if (isOperator(c)) {
            // Pop top two elements
            string op1 = st.top(); st.pop();
            string op2 = st.top(); st.pop();

            // Form the infix expression
            string expr = "(" + op1 + c + op2 + ")";
            
            // Push back to stack
            st.push(expr);
        } else {
            // Operand, push to stack
            st.push(string(1, c));
        }
    }
    
    // The final infix expression
    return st.top();
}

int main() {
    string prefix = "*-A/BC-/AKL";
    cout << preToInfix(prefix) << endl;
    return 0;
}
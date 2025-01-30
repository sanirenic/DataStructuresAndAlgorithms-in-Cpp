/*You are given a string that represents the prefix form of a valid mathematical expression. 
Convert it to its postfix form.*/

#include <iostream>
#include <stack>
using namespace std;

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '%' || c == '^');
}

string preToPost(string pre_exp) {
    stack<string> st;
    int n = pre_exp.length();

    // Traverse from right to left
    for (int i = n - 1; i >= 0; i--) {
        char c = pre_exp[i];

        if (isOperator(c)) {
            // Pop top two elements
            string op1 = st.top(); st.pop();
            string op2 = st.top(); st.pop();

            // Form the postfix expression
            string expr = op1 + op2 + c;
            
            // Push back to stack
            st.push(expr);
        } else {
            // Operand, push to stack
            st.push(string(1, c));
        }
    }

    // The final postfix expression
    return st.top();
}

int main() {
    string prefix = "*-A/BC-/AKL";
    cout << preToPost(prefix) << endl;
    return 0;
}

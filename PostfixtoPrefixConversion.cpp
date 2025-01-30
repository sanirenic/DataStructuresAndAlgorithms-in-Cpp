/*You are given a string that represents the postfix form of a valid mathematical expression. 
Convert it to its prefix form.*/

#include <iostream>
#include <stack>
using namespace std;

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

string postToPre(string post_exp) {
    stack<string> st;
    
    for (char c : post_exp) {
        if (isOperator(c)) {
            // Pop top two elements
            string op2 = st.top(); st.pop();
            string op1 = st.top(); st.pop();
            
            // Form the prefix expression
            string expr = c + op1 + op2;
            
            // Push the new expression back onto the stack
            st.push(expr);
        } else {
            // If it's an operand, push it as a string
            st.push(string(1, c));
        }
    }

    // The final prefix expression is on top of the stack
    return st.top();
}

int main() {
    string postfix = "ABC/-AK/L-*";
    cout << "Prefix: " << postToPre(postfix) << endl;
    return 0;
}
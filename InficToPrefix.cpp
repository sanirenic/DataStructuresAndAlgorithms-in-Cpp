/*Infix to Prefix

Problem Statement: Given an infix expression, 
Your task is to convert the given infix expression to a prefix expression.*/

#include <bits/stdc++.h>
using namespace std;


int precedence(char c) {
    if (c == '^') return 3;
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return -1;
}


string infixToPrefix(string infix) {
    reverse(infix.begin(), infix.end());

    
    for (int i = 0; i < infix.length(); i++) {
        if (infix[i] == '(') infix[i] = ')';
        else if (infix[i] == ')') infix[i] = '(';
    }

    stack<char> operators;
    string prefix;

    for (char c : infix) {
        if (isalnum(c)) {
            prefix += c;  
        } else if (c == '(') {
            operators.push(c);
        } else if (c == ')') {
            while (!operators.empty() && operators.top() != '(') {
                prefix += operators.top();
                operators.pop();
            }
            operators.pop();
        } else { 
            while (!operators.empty() && precedence(operators.top()) >= precedence(c)) {
                prefix += operators.top();
                operators.pop();
            }
            operators.push(c);
        }
    }

    while (!operators.empty()) {
        prefix += operators.top();
        operators.pop();
    }

    reverse(prefix.begin(), prefix.end());
    return prefix;
}


int main() {
    string infix = "(A-B/C)*(A/K-L)";
    cout << "Prefix Expression: " << infixToPrefix(infix) << endl;
    return 0;
}

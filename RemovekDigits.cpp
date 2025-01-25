/*402. Remove K Digits

Given string num representing a non-negative integer num, and an integer k, 
return the smallest possible integer after removing k digits from num.*/

#include <iostream>
#include <string>
#include <stack>
using namespace std;

string removeKdigits(string num, int k){
    stack<char>st;
    for(char c:num){
        while(!st.empty() && st.top() > c && k>0){
            st.pop();
            k--;
        }
        if(!st.empty()||c!='0'){
            st.push(c);
        }
    }
    while(k>0 && !st.empty()){
        st.pop();
        k--;
    }
    if(st.empty()) return "0";
    string result="";
    while(!st.empty()){
        result=st.top()+result;
        st.pop();
    }
    return result;
}

int main() {
    cout << removeKdigits("1432219", 3) << endl; 
    cout << removeKdigits("10200", 1) << endl; 
    cout << removeKdigits("10", 2) << endl;  
    return 0;
}
/*Given an array, find the nearest smaller element G[i] for every element A[i] in the array such that the element has an index smaller than i.

More formally,

    G[i] for an element A[i] = an element A[j] such that 
    j is maximum possible AND 
    j < i AND
    A[j] < A[i]
Elements for which no smaller element exist, consider next smaller element as -1.*/
#include <bits/stdc++.h>
using namespace std;

vector<int> nearestSmallerElementsUsingStack(vector<int>&A){
    int n=A.size();
    vector<int>G(n, -1);
    stack<int>st;

    for(int i=0; i<n; i++){
        while(!st.empty() && st.top()>=A[i]){
            st.pop();
        }
        if(!st.empty()){
            G[i]=st.top();

        }
        st.push(A[i]);
    }
    return G;
}

int main() {
    vector<int> A = {4, 5, 2, 10, 8};
    vector<int> G = nearestSmallerElementsUsingStack(A);

    cout << "Nearest smaller elements (Using Stack): ";
    for (int g : G) {
        cout << g << " ";
    }
    return 0;
}
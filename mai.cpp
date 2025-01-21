#include<iostream>
using namespace std;

int factorial(int x){
    int ans=1;
    for(int i=1; i<=x; i++){
        ans =ans*i;
    }
    return ans;
}
int main() {
    int x=5;
    int result=factorial(x);
    cout<<"the factorial of "<<x<<" is "<<result;
    return 0;
}
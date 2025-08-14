#include <bits/stdc++.h>
using namespace std;

pair<int, int> findMissingAndRepeatingNum(vector<int> arr){
    long long n=arr.size();
    long long s=n*(n+1)/2;
    long long s2=n*(n+1)*(2*n+1)/6;
    long long sum=0, sumSq=0;

    for(long long num:arr){
        sum+=num;
        sumSq+=1LL*num*num;

    }

        long long diff1=sum-s;
        long long diff2=sumSq-s2;

        long long sumAB=diff2/diff1;
        long long A=(diff1+sumAB)/2;
        long long B=A-diff1;

        return{(int)A, (int)B};
}

int main() { vector<int> arr = {3, 1, 2, 5, 3}; 
auto ans = findMissingAndRepeatingNum(arr); 
cout << ans.first << " " << ans.second << endl;
}
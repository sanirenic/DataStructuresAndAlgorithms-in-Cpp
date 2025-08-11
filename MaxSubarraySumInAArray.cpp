#include <bits/stdc++.h>
using namespace std;

int maxSubarray(vector<int> &arr){
    int maxSum=INT_MIN;
    int currentSum=0;

    for(int num:arr){
        currentSum+=num;
        maxSum=max(maxSum, currentSum);

        if(currentSum<0) currentSum=0;

    }
    return maxSum;
}

int main(){
    vector<int> arr = {1, 5, -2, 4, -6, 10, 11};
    cout<< "Max Sum is : "<<maxSubarray(arr)<<endl;

    return 0;
}
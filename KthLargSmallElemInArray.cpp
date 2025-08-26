#include <bits/stdc++.h>
using namespace std;

int partition(vector<int> & arr, int l, int r){
    int pivot=arr[r];
    int i=l;
    for(int j=l; j<=r; j++){
        if(arr[j]<=pivot){
            swap(arr[i], arr[j]);
            i++;
        }
    }
    swap(arr[i], arr[r]);
    return i;
}

int quickSelect(vector<int> &arr, int l, int r, int k){
    if(l<=r){
        int pi=partition(arr, l, r);
        if(pi==k) return arr[pi];
        else if(pi>k) return quickSelect(arr, l, pi-1, k);
        else return quickSelect(arr, pi+1, r, k);
    }
    return -1;
}

int main() {
    vector<int> arr = {1,2,6,4,5,3};
    int k = 3;
    int n = arr.size();

    cout << "Kth smallest = " << quickSelect(arr, 0, n-1, k-1) << endl;
    cout << "Kth largest = " << quickSelect(arr, 0, n-1, n-k) << endl;
}

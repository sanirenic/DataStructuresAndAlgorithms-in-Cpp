#include <bits/stdc++.h>
using namespace std;

void mergeArray(vector<int> &arr1, vector<int> &arr2){
    int n=arr1.size(), m=arr2.size();
    int gap=ceil((n+m)/2.0);

    auto nextGap=[](int g) -> int{
        if(g<=1) return 0;
        return(g/2)+(g%2);
    };
    while(gap>0){
        int i=0, j=gap;
        wgile(j<(n+m)){
            if(i<n && j<n && arr1[i]>arr1[j])
            swap(arr1[i], arr1[j]);

            else if(i<n && j>=n && arr1[i]>arr2[j-n])
            swap(arr1[i], arr2[j-n]);

            else if(i>=n && j>=n && arr2[i-n]>arr2[j-n])
            swap(arr2[i-n], arr2[j-n]);

            i++, j++;
        }
        gap=nextGap(gap);
    }
}

int main() {
    vector<int> arr1 = {1, 3, 5, 7};
    vector<int> arr2 = {0, 2, 6, 8, 9};
    mergeArray(arr1, arr2);

    cout << "arr1: ";
    for (int x : arr1) cout << x << " ";
    cout << "\narr2: ";
    for (int x : arr2) cout << x << " ";
}

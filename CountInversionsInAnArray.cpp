#include <bits/stdc++.h>
using namespace std;

int merge(vector<int> &arr, int low, int mid, int high) {
    vector<int> temp;
    int left = low;
    int r = mid + 1;  // renamed from right → r
    int cnt = 0;

    while (left <= mid && r <= high) {
        if (arr[left] <= arr[r]) {
            temp.push_back(arr[left]);
            left++;
        } else {
            temp.push_back(arr[r]);
            cnt += (mid - left + 1);
            r++;
        }
    }
    while (left <= mid) {
        temp.push_back(arr[left]);
        left++;
    }
    while (r <= high) {
        temp.push_back(arr[r]);
        r++;
    }

    for (int i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }
    return cnt;
}

int mergeSort(vector<int> &arr, int low, int high) {
    int cnt = 0;
    if (low >= high) return cnt;
    int mid = (low + high) / 2;
    
    cnt += mergeSort(arr, low, mid);
    cnt += mergeSort(arr, mid + 1, high);
    cnt += merge(arr, low, mid, high);

    return cnt;
}

int numberOfInversions(vector<int> &a, int n) {
    return mergeSort(a, 0, n - 1);
}

int main() {
    vector<int> a = {5, 4, 3, 2, 1};
    int n = 5;
    int cnt = numberOfInversions(a, n);
    cout << "The number of inversions are: " << cnt << endl;
    return 0;
}

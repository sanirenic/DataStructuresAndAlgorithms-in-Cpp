/*You are given an array arr of N integers representing a min Heap. 
The task is to convert it to max Heap.

A max-heap is a complete binary tree in which the value in each internal node is 
greater than or equal to the values in the children of that node. */

#include <bits/stdc++.h>
using namespace std;

void maxHeapify(vector<int>& arr, int n, int i) {
    int largest = i;         
    int left = 2 * i + 1;    
    int right = 2 * i + 2;   

    
    if (left < n && arr[left] > arr[largest])
        largest = left;

    
    if (right < n && arr[right] > arr[largest])
        largest = right;

    
    if (largest != i) {
        swap(arr[i], arr[largest]);
        maxHeapify(arr, n, largest);
    }
}


void convertMinToMaxHeap(vector<int>& arr, int n) {
    
    for (int i = (n - 2) / 2; i >= 0; i--) {
        maxHeapify(arr, n, i);
    }
}


int main() {
    vector<int> arr = {1, 2, 3, 4};
    int n = arr.size();

    convertMinToMaxHeap(arr, n);

    
    for (int num : arr)
        cout << num << " ";
    cout << endl;

    return 0;
}

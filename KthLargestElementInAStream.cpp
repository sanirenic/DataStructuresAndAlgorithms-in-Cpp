/*You are part of a university admissions office and need to keep track of the kth highest 
test score from applicants in real-time. 
This helps to determine cut-off marks for interviews and admissions dynamically as new applicants 
submit their scores.

You are tasked to implement a class which, for a given integer k, 
maintains a stream of test scores and continuously returns the kth highest test score after a new score 
has been submitted. More specifically, 
we are looking for the kth highest score in the sorted list of all scores.

Implement the KthLargest class:

KthLargest(int k, int[] nums) Initializes the object with the integer k and the stream of test scores nums.
int add(int val) Adds a new test score val to the stream and returns the element representing
 the kth largest element in the pool of test scores so far.*/


#include <iostream>
#include <queue>
#include <vector>
using namespace std;


class KthLargest{
    public: 
    priority_queue<int, vector<int>, greater<int>> minHeap;

    int K;

    KthLargest(int k, vector<int>& nums){
        this-> K=k;
        for(int num:nums){
            add(num);
        }
    }

    int add(int val){
        if(minHeap.size() < K){
            minHeap.push(val);
        }
        else if(val > minHeap.top()){
            minHeap.pop();
            minHeap.push(val);
        }
        return minHeap.top();
    }
};


 int main() {
    vector<int> nums = {4, 5, 8, 2};
    KthLargest kthLargest(3, nums);
    cout << kthLargest.add(3) << endl; // Output: 4
    cout << kthLargest.add(5) << endl; // Output: 5
    cout << kthLargest.add(10) << endl; // Output: 5
    cout << kthLargest.add(9) << endl; // Output: 8
    cout << kthLargest.add(4) << endl; // Output: 8
    return 0;
}
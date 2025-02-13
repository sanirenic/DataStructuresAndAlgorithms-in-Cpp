/*Find length of the longest subarray containing atmost two distinct integers

Given an array arr[] containing positive elements, 
the task is to find the length of the longest subarray of an input array containing
 at most two distinct integers.*/

#include <bits/stdc++.h>
using namespace std;

int longestSubarraySlidingWindow(vector<int>& arr) {
    unordered_map<int, int> freq;
    int left = 0, maxLength = 0;

    for (int right = 0; right < arr.size(); right++) {
        freq[arr[right]]++; // Add current element to map

        // If more than 2 distinct numbers, shrink window from left
        while (freq.size() > 2) {
            freq[arr[left]]--;
            if (freq[arr[left]] == 0) {
                freq.erase(arr[left]); // Remove from map if count becomes 0
            }
            left++;
        }

        maxLength = max(maxLength, right - left + 1);
    }

    return maxLength;
}

int main() {
    vector<int> arr = {3, 1, 2, 2, 2, 2};
    cout << longestSubarraySlidingWindow(arr) << endl; // Output: 5
    return 0;
}

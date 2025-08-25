#include <bits/stdc++.h>
using namespace std;

bool isPossible(vector<int>& nums, int m, int limit) {
    int students = 1, pages = 0;
    for (int x : nums) {
        if (pages + x > limit) {
            students++;
            pages = x;
            if (students > m) return false;
        } else {
            pages += x;
        }
    }
    return true;
}

int allocateBooks(vector<int>& nums, int m) {
    int n = nums.size();
    if (m > n) return -1;

    int low = *max_element(nums.begin(), nums.end());
    int high = accumulate(nums.begin(), nums.end(), 0);
    int ans = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (isPossible(nums, m, mid)) {
            ans = mid;
            high = mid - 1; // minimize
        } else {
            low = mid + 1;
        }
    }
    return ans;
}

int main() {
    vector<int> nums = {12, 34, 67, 90};
    int m = 2;
    cout << allocateBooks(nums, m) << endl; // 113
}

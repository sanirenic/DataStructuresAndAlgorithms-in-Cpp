#include <bits/stdc++.h>
using namespace std;

bool canJump(vector<int>& nums) {
    int maxReach = 0;
    
    for (int i = 0; i < nums.size(); i++) {
        if (i > maxReach) return false; // can't reach this index
        maxReach = max(maxReach, i + nums[i]);
    }
    
    return true;
}

int main() {
    vector<int> nums1 = {2, 3, 1, 1, 4};
    vector<int> nums2 = {3, 2, 1, 0, 4};

    cout << boolalpha << canJump(nums1) << endl; // true
    cout << boolalpha << canJump(nums2) << endl; // false

    return 0;
}

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xor_all = 0;

        // Step 1: XOR all elements
        for (int num : nums) {
            xor_all ^= num;
        }

        // Step 2: Find a set bit (rightmost set bit)
        int diff_bit = xor_all & (-xor_all);  // isolates rightmost 1-bit

        int x = 0, y = 0;

        // Step 3: Divide into two groups based on diff_bit
        for (int num : nums) {
            if (num & diff_bit)
                x ^= num;  // group where diff_bit is set
            else
                y ^= num;  // group where diff_bit is not set
        }

        // Step 4: Return in ascending order
        if (x > y) swap(x, y);
        return {x, y};
    }
};

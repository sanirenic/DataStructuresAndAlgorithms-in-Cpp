#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
using namespace std;

vector<int> maxSumCombinations(vector<int>& nums1, vector<int>& nums2, int k) {
    sort(nums1.rbegin(), nums1.rend()); // sort descending
    sort(nums2.rbegin(), nums2.rend());

    int n = nums1.size();
    int m = nums2.size();

    // Max heap: {sum, {i, j}}
    priority_queue<pair<int, pair<int, int>>> maxHeap;

    // Set to track used indices
    set<pair<int, int>> used;

    // Start with the max sum
    maxHeap.push({nums1[0] + nums2[0], {0, 0}});
    used.insert({0, 0});

    vector<int> result;

    while (k-- && !maxHeap.empty()) {
        auto top = maxHeap.top();
        maxHeap.pop();

        int sum = top.first;
        int i = top.second.first;
        int j = top.second.second;

        result.push_back(sum);

        // Push next possible pair (i+1, j)
        if (i + 1 < n && used.find({i + 1, j}) == used.end()) {
            maxHeap.push({nums1[i + 1] + nums2[j], {i + 1, j}});
            used.insert({i + 1, j});
        }

        // Push next possible pair (i, j+1)
        if (j + 1 < m && used.find({i, j + 1}) == used.end()) {
            maxHeap.push({nums1[i] + nums2[j + 1], {i, j + 1}});
            used.insert({i, j + 1});
        }
    }

    return result;
}

int main() {
    vector<int> nums1 = {3, 4, 5};
    vector<int> nums2 = {2, 6, 3};
    int k = 2;

    vector<int> res = maxSumCombinations(nums1, nums2, k);
    for (int val : res)
        cout << val << " ";
    return 0;
}

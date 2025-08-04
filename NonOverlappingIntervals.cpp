#include <bits/stdc++.h>
using namespace std;

int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    // Sort intervals by their ending times
    sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b) {
        return a[1] < b[1];
    });

    int end = INT_MIN; // To keep track of the end of the last added interval
    int remove = 0;    // Number of intervals to remove

    for (auto& interval : intervals) {
        if (interval[0] < end) {
            // Overlap detected
            remove++;
        } else {
            // No overlap, update the end
            end = interval[1];
        }
    }

    return remove;
}

int main() {
    vector<vector<int>> intervals1 = {{1, 2}, {2, 3}, {3, 4}, {1, 3}};
    vector<vector<int>> intervals2 = {{1, 3}, {1, 4}, {3, 5}, {3, 4}, {4, 5}};

    cout << eraseOverlapIntervals(intervals1) << endl; // Output: 1
    cout << eraseOverlapIntervals(intervals2) << endl; // Output: 2

    return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Variant 1
string twoSumTwoPointers_1(vector<int>& arr, int target) {
    int n = arr.size();
    vector<pair<int, int>> vec; // {value, index}

    for (int i = 0; i < n; i++)
        vec.push_back({arr[i], i});

    sort(vec.begin(), vec.end());

    int left = 0, right = n - 1;

    while (left < right) {
        int sum = vec[left].first + vec[right].first;
        if (sum == target)
            return "YES";
        else if (sum < target)
            left++;
        else
            right--;
    }

    return "NO";
}

// Variant 2
pair<int, int> twoSumTwoPointers_2(vector<int>& arr, int target) {
    int n = arr.size();
    vector<pair<int, int>> vec; // {value, index}

    for (int i = 0; i < n; i++)
        vec.push_back({arr[i], i});

    sort(vec.begin(), vec.end());

    int left = 0, right = n - 1;

    while (left < right) {
        int sum = vec[left].first + vec[right].first;
        if (sum == target)
            return {vec[left].second, vec[right].second};
        else if (sum < target)
            left++;
        else
            right--;
    }

    return {-1, -1};
}

int main() {
    vector<int> arr = {2, 6, 5, 8, 11};
    int target = 14;

    // Try different approaches
    cout << "Variant 1 (YES/NO): " << twoSumHashing_1(arr, target) << endl;
    
    pair<int, int> result = twoSumHashing_2(arr, target);
    cout << "Variant 2 (indices): [" << result.first << ", " << result.second << "]" << endl;

    return 0;
}

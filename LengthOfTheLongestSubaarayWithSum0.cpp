#include <iostream>
#include <unordered_map>
using namespace std;

int maxLen(int A[], int n) {
    unordered_map<int, int> mpp; // sum -> index
    int maxi = 0;
    int sum = 0;

    for (int i = 0; i < n; i++) {
        sum += A[i];

        // Case 1: If the sum is 0, max length is i+1
        if (sum == 0) {
            maxi = i + 1;
        }
        // Case 2: If this sum was seen before
        else if (mpp.find(sum) != mpp.end()) {
            maxi = max(maxi, i - mpp[sum]);
        }
        // Case 3: Store this sum with index if not seen before
        else {
            mpp[sum] = i;
        }
    }

    return maxi;
}

int main() {
    int A[] = {15, -2, 2, -8, 1, 7, 10, 23};
    int n = sizeof(A) / sizeof(A[0]);

    cout << "Length of the longest subarray with sum 0 is: " << maxLen(A, n) << endl;

    return 0;
}

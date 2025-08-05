#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int averageWaitingTime(vector<int>& bt) {
    sort(bt.begin(), bt.end());  // SJF: sort burst times
    int n = bt.size();
    int total_waiting_time = 0;
    int current_time = 0;

    for (int i = 0; i < n; i++) {
        total_waiting_time += current_time;
        current_time += bt[i];
    }

    return total_waiting_time / n;  // Floor is default for integers
}

int main() {
    vector<int> bt1 = {4, 1, 3, 7, 2};
    cout << averageWaitingTime(bt1) << endl;  // Output: 4

    vector<int> bt2 = {1, 2, 3, 4};
    cout << averageWaitingTime(bt2) << endl;  // Output: 2

    return 0;
}

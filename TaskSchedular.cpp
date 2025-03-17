#include <bits/stdc++.h>
using namespace std;

int leastInterval(vector<char>& tasks, int n) {
    unordered_map<char, int> freq;
    for (char task : tasks) freq[task]++;
    
    priority_queue<int> maxHeap;
    for (auto& it : freq) maxHeap.push(it.second);
    
    queue<pair<int, int>> cooldown;
    int time = 0;
    
    while (!maxHeap.empty() || !cooldown.empty()) {
        time++;

        // If there's a task to execute
        if (!maxHeap.empty()) {
            int cnt = maxHeap.top() - 1;
            maxHeap.pop();
            if (cnt > 0) cooldown.push({cnt, time + n});
        }

        // If the cooldown period has passed, push back into the heap
        if (!cooldown.empty() && cooldown.front().second == time) {
            maxHeap.push(cooldown.front().first);
            cooldown.pop();
        }
    }

    return time;
}

int main() {
    vector<char> tasks = {'A', 'A', 'A', 'B', 'B', 'B'};
    int n = 2;
    cout << leastInterval(tasks, n) << endl;  // Output: 8
    return 0;
}


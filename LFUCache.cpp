/* LFU Cache
Design and implement a data structure for a Least Frequently Used (LFU) cache.

Implement the LFUCache class:

LFUCache(int capacity) Initializes the object with the capacity of the data structure.
int get(int key) Gets the value of the key if the key exists in the cache. Otherwise, returns -1.
void put(int key, int value) Update the value of the key if present, or inserts the key if not already present. 
When the cache reaches its capacity, it should invalidate and remove the least frequently used key before inserting a new item. 
For this problem, when there is a tie (i.e., two or more keys with the same frequency), 
the least recently used key would be invalidated.
To determine the least frequently used key, a use counter is maintained for each key in the cache. 
The key with the smallest use counter is the least frequently used key.

When a key is first inserted into the cache, its use counter is set to 1 (due to the put operation). 
The use counter for a key in the cache is incremented either a get or put operation is called on it.

The functions get and put must each run in O(1) average time complexity.*/


#include<iostream>
#include<bits/stdc++.h>
#include <unordered_set> 
#include <vector>
using namespace std;

class LFUCache{
    int capacity, time;
    unordered_map<int, int> values;
    unordered_map<int, int> freq;
    unordered_map<int, int> lastUsed;
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> minHeap;

    public:
    LFUCache(int capacity){
        this->capacity=capacity;
        this->time=0;
    }
    int get(int key){
        if(values.find(key)==values.end()) return -1;
        freq[key]++;
        lastUsed[key]=time++;
        minHeap.push({freq[key], lastUsed[key], key});
        return values[key];
    }
    void put(int key, int value){
        if(capacity==0) return;
        if(values.size()>=capacity && values.find(key) == values.end()){
            while(!minHeap.empty()){
                auto[f, t, k]=minHeap.top();
                if(frq[k]==f && lastUsed[k]==t){
                    values.erase(k);
                    freq.erase(k);
                    lastUsed.erase(k);
                    minHeap.pop();
                    break;
                }
                minHeap.pop();
            }
        }
        values[key]=value;
        freq[key]++;
        lastUsed=time++;
        minHeap({freq[key], lastUsed[key], key});
    }
};

int main() {
    LFUCache lfu(2); // Create LFU cache with capacity 2

    lfu.put(1, 1);   
    lfu.put(2, 2);
    cout << lfu.get(1) << endl; // returns 1

    lfu.put(3, 3);   // Removes key 2 (LFU)
    cout << lfu.get(2) << endl; // returns -1 (not found)
    cout << lfu.get(3) << endl; // returns 3

    lfu.put(4, 4);   // Removes key 1 (LFU)
    cout << lfu.get(1) << endl; // returns -1 (not found)
    cout << lfu.get(3) << endl; // returns 3
    cout << lfu.get(4) << endl; // returns 4

    return 0;
}

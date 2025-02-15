#include <iostream>
#include <vector>

using namespace std;

class MinHeap{
    private:
    vector<int>heap;
    void heapifyUp(int index){
        int parent=(index-1)/2;
        while(index>0 && heap[index]<heap[parent]){
            swap(heap[index], heap[parent]);
            index=parent;
            parent=(index-1)/2;
        }
    }
    void heapifyDown(int index){
        int left=2*index+1;
        int right=2*index+2;
        int smallest=index;
        if(left<heap.size() && heap[left]<heap[smallest])
        smallest=left;
        if(right<heap.size() && heap[right]<heap[smallest])
        smallest=right;
        if(smallest!=index){
            swap(heap[index], heap[smallest]);
            heapifyDown(smallest);
        }
    }
    public:
    void insertKey(int x){
        heap.push_back(x);
        heapifyUp(heap.size()-1);
    }
    void deleteKey(int i){
        if(i>=heap.size()) return;
        heap[i]=heap.back();
        heap.pop_back();
        heapifyDown(i);
    }
    int extractMin(){
        if(heap.empty()) return -1;
        int minVal=heap[0];
        heap[0]=heap.back();
        heap.pop_back();
        heapifyDown(0);
        return minVal;
    }
};

int main() {
    MinHeap pq;
    pq.insertKey(4);
    pq.insertKey(2);
    cout << pq.extractMin() << " ";  // Output: 2
    pq.insertKey(6);
    pq.deleteKey(0);
    cout << pq.extractMin() << " ";  // Output: 6
    cout << pq.extractMin() << endl; // Output: -1
    return 0;
}

/*Given a binary heap implementation of Priority Queue. 
Extract the maximum element from the queue i.e. remove it from the Queue and return it's value.*/

#include <iostream>
#include <vector>
using namespace std;

class MaxHeap{
    private:
    vector<int>heap;
    void heapifyDown(int i){
        int largest=i;
        int left=2*i+1;
        int right=2*i+2;

        if(left<heap.size() && heap[left]>heap[largest])
        largest=left;

        if(right<heap.size() && heap[right]>heap[largest])
        largest=right;

        if(largest!=i){
            swap(heap[i], heap[largest]);
            heapifyDown(largest);
        }
    }
    public:
    MaxHeap(vector<int> arr){
        heap=arr;
        for(int i=heap.size()/2-1; i>=0; i--){
            heapifyDown(i);
        }
    }
    int extractMax(){
        if(heap.empty()) return -1;
        int maxVal=heap[0];
        heap[0]=heap.back();
        heap.pop_back();
        heapifyDown(0);
        return maxVal;
    }
    void printHeap(){
        for(int val:heap) cout<<val<<" ";
        cout<<endl;
    }
};




int main() {
    vector<int> arr = {4, 2, 8, 16, 24, 2, 6, 5};
    MaxHeap pq(arr);
    cout << "Max: " << pq.extractMax() << endl;
    cout << "Priority Queue after extraction: ";
    pq.printHeap();
    return 0;
}

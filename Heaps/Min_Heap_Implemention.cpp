// using complete binary tree.
// A complete binary tree is a binary tree in which every level, except possibly the last, is completely filled, and all nodes are as far left as possible. 
// insert,removing - O(log(n)),get min/max - O(1)
// We can use a vector or an array for this.
// A[(2*i)+1] -> Left child 
// A[(2*i)+2] -> Right Child
// A[(i-1)/2] -> Parent node
// To check for valid max-heap 1)It should be a complete binary tree 2)The root value should be less than child value


#include<bits/stdc++.h>
using namespace std;

void swap(int*x,int*y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

class MinHeap {
    int *heap; //pointer to array of elements
    int capacity;
    int heap_size;
    public:
    // constructor
    MinHeap(int cap) {
        heap_size = 0;
        capacity = cap;
        heap = new int[cap];
    }
    // get parent index
    int getParent(int i) {
        return (i-1)/2;
    }
    // get left child index
    int getLeftChild(int i) {
        return (2*i)+1;
    }
    // get right child index
    int getRightChild(int i) {
        return (2*i)+2;
    }
    // insert
    void insertHeap(int x) {
        if (heap_size == capacity) {
            cout<<"Maximum Capacity Reached"<<"\n";
            return;
        }
        // 1)inserting it to the end
        heap_size++;
        int i = heap_size - 1;
        heap[i] = x;
        // 2)Fix the condition if violated by swapping
        while(i !=0 && heap[getParent(i)] > heap[i]) {
            // swap the parent and child
            swap(&heap[i],&heap[getParent(i)]);
            // change i
            i = getParent(i);
        }
    }
    // remove minimum element or pop the root
    int removeMin() {
        if (heap_size <= 0) return INT_MAX;
        if(heap_size == 1) {
            heap_size--;
            return heap[0];
        }
        int root = heap[0];
        heap[0] = heap[heap_size-1];
        heap_size--;
        MinHeapify(0);
        return root;
    }
    // a recursive method to heapify a subtree
    void MinHeapify(int i) {
        int l = getLeftChild(i);
        int r = getRightChild(i);
        int smallest = i;
        if(l<heap_size && heap[l]<heap[i]){
            smallest = l;
        }
        if(r<heap_size && heap[r]<heap[i]){
            smallest = r;
        }
        if(smallest != i){
            swap(&heap[smallest],&heap[i]);
            MinHeapify(smallest);
        }
    }
    // decrease the value to a particular element to a new value
    void decreaseValue(int i,int newValue) {
        heap[i] = newValue;
        while(i!=0 && heap[getParent(i)]>heap[i]){
            swap(&heap[getParent(i)],&heap[i]);
            i = getParent(i);
        }
    }
    // delete a particular element
    void deleteHeap(int i) {
        // 1)decrese the value to INT_MIN and then remove
        decreaseValue(i,INT_MIN);
        // 2)remove minimum
        removeMin();
    }
};


int main() {
    MinHeap h(7);
    h.insertHeap(5);
    h.insertHeap(15);
    h.insertHeap(10);
    h.insertHeap(18);
    h.insertHeap(16);
    cout<<"The minimum element of heap is : "<<h.removeMin()<<"\n";
    // cout<<"The minimum element of heap is : "<<h.removeMin()<<"\n";
    // cout<<"The minimum element of heap is : "<<h.removeMin()<<"\n";
    h.deleteHeap(10);
    cout<<"Afeter deleting Minimum element of heap is : "<<h.removeMin()<<"\n";
}
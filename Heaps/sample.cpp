#include<bits/stdc++.h>
using namespace std;







































class MinHeap{
    int *heap;
    int capacity;
    int heap_size;
    MinHeap(int cap){
        heap_size = 0;
        capacity = cap;
        heap = new int[capacity];
    }
    void swap(int *x,int *y){
        int temp = *x;
        *x = *y;
        *y = temp;
    }
    int getParent(int i){
        return (i-1)/2;
    }
    int getLeftChild(int i) {
        return 2*i+1;
    }
    int getRightChild(int i) {
        return 2*i+2;
    }
    // insert into heap
    void insert(int x){
        if(heap_size >= capacity){
            cout<<"Not enough space";
            return;
        }
        heap_size++;
        int i = heap_size - 1;
        heap[i] = x;
        while(i!=0 && heap[getParent(i)] > heap[i]){
            swap(&heap[getParent(i)],&heap[i]);
            i = getParent(i);
        }
    }
    void MinHeapify(int i){
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
    int removeMin(){
        if(heap_size == 0){
            return INT_MAX;
        }
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
    void decreaseValue(int i,int val){
        heap[i] = val;
        while(i!=0 && heap[getParent(i)] > heap[i]){
            swap(&heap[getParent(i)],&heap[i]);
            i = getParent(i);
        }
    }
    void deleteHeap(int i){
        decreaseValue(i,INT_MIN);
        removeMin();
    }
};
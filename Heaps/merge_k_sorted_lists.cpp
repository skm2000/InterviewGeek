#include<bits/stdc++.h>
using namespace std;

// O(NlogK) solution
// v.imp question,submitted in leetcode

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    struct compare{
        bool operator()(const ListNode *x,const ListNode *y){
            return x->val > y->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*,vector<ListNode*>,compare>min_heap;
//         push root of each list in a min_heap;
        for(auto root:lists){
            if(root != nullptr){
                min_heap.push(root);
            }
        }
        ListNode *head = NULL, *tail = NULL;
        while(!min_heap.empty()){
            ListNode* node = min_heap.top();
            min_heap.pop();
            if(head == NULL){
                head = node;
                tail = node;
            }
            else{
                tail->next = node;
                tail = tail->next;
            }
            if(node->next != NULL){
                min_heap.push(node->next);
            }
        }
        return head;
    }
};
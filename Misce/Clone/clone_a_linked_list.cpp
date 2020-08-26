#include <bits/stdc++.h>
using namespace std;

// problem : https://leetcode.com/problems/copy-list-with-random-pointer/

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return NULL;
        unordered_map<Node*,Node*>mp;
        Node* originalCurr = head;
        Node* cloneCurr = NULL;
        while(originalCurr != NULL){
            cloneCurr = new Node(originalCurr->val);
            mp[originalCurr] = cloneCurr;
            originalCurr = originalCurr->next;
        }
        originalCurr = head;
        while(originalCurr != NULL){
            cloneCurr= mp[originalCurr];
            cloneCurr->next = mp[originalCurr->next];
            cloneCurr->random = mp[originalCurr->random];
            originalCurr = originalCurr->next;
        }
        return mp[head];
    }
};
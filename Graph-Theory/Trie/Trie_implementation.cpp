#include<bits/stdc++.h>
using namespace std;

class TrieNode {
public:

    bool end;
    TrieNode* children[26];
    TrieNode() {
        end = false;
        memset(children, NULL, sizeof(children));
    }

    //creation of root
    TrieNode *root = new TrieNode();
    
    //inserting new node in trie
    void insert(string word){
        TrieNode *node = root;
        for(char c:word) {
            if(!node->children[c-'a']){
                node->children[c-'a'] = new TrieNode();
            }
            node = node->children[c-'a'];
        }
        node->end = true;
    }

    //searching a node in a trie
    bool search(string word) {
        TrieNode *node = root;
        for(char c:word) {
            if(!node->children[c-'a']){
                return false;
            }
            node = node->children[c-'a'];
        }
        return node->end;
    }

    //deletion of a node in trie
    void remove(string word) {
        if(word.size() == 0) {
            root->end = false;
        }
        TrieNode *child;
        int index = word[0] - 'a';
        if(root->children[index] != NULL){
            child = root->children[index];
        }
        else {
            return;
        }
        //remove useless child
        if(child->end == false){
            for(int i=0;i<26;i++){
                if(root->children != NULL){
                    return;
                }
            }
            delete child;
        }
    }
};

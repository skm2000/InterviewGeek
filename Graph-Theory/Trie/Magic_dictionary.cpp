#include<bits/stdc++.h>
using namespace std;

class Trie{
public:
    Trie* children[26];
    bool end;
    Trie(){
        memset(children, NULL, sizeof(children));
        end = false;
    }
};
class MagicDictionary {
private:
    Trie *root = new Trie();
public:
    /** Initialize your data structure here. */
    MagicDictionary() {
        
    }
    void insert(string s){
        Trie* node = root;
        for(char c : s){
            if(!node -> children[c - 'a']){
                node -> children[c - 'a'] = new Trie();
            }
            node  = node -> children[c - 'a'];
        }
        node -> end = true;
    }
    /** Build a dictionary through a list of words */
    void buildDict(vector<string> dict) {
        for(int i = 0; i < dict.size(); i++){
            insert(dict[i]);
        }
    }
    bool found(string s){
        Trie* node = root;
        for(char c : s){
            if(!node -> children[c - 'a']){
                return false;
            }
            node = node -> children[c - 'a'];
        }
        return node -> end;
    }
    /** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
    bool search(string word) {
        for(int i = 0; i < word.length(); i++){
            char c = word[i];
            for(char ch = 'a'; ch <= 'z'; ch++){
                if(ch == c) continue;
                word[i] = ch;
                if(found(word)){
                    return true;
                }
            }
            word[i] = c;
        }
        return false;
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dict);
 * bool param_2 = obj->search(word);
 */
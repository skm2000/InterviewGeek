#include<bits/stdc++.h>
using namespace std;

// problem : https://leetcode.com/problems/lru-cache/

// v.imp question
class LRUCache {
    deque<int>dq;
    unordered_map<int,int>mp;
    int c;
public:
    LRUCache(int capacity) {
       c = capacity;
    }
    
    int get(int key) {
        auto it = find(dq.begin(),dq.end(),key);
        if(it != dq.end()){
            dq.erase(it);
            dq.push_back(key);
            return mp[key];
        }
        return -1;
    }
    
    void put(int key, int value) {
        auto it = find(dq.begin(),dq.end(),key);
        if(it == dq.end()){
            if(dq.size() == c){
                mp.erase(dq.front());
                dq.pop_front();
            }
            dq.push_back(key);
            mp[key] = value;
        }
        else{
            mp[key]=value;
            dq.erase(it);
            dq.push_back(key);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */




// faster approach
class LRUCache {
private:
    int capacity;
    list<int> recent;
    unordered_map<int, int> cache;
    unordered_map<int, list<int>::iterator> pos; // to map the position
    void use(int key) {
        if (pos.find(key) != pos.end()) {
            recent.erase(pos[key]);
        } else if (recent.size() >= capacity) {
            int old = recent.back();
            recent.pop_back();
            cache.erase(old);
            pos.erase(old);
        }
        recent.push_front(key);
        pos[key] = recent.begin();
    }
public:
    LRUCache(int capacity): capacity(capacity) {}
    int get(int key) {
        if (cache.find(key) != cache.end()) {
            use(key);
            return cache[key];
        }
        return -1;
    }
    void put(int key, int value) {
        use(key);
        cache[key] = value;
    }
};
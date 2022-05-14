#include <bits/stdc++.h>
class LRUCache {
public:
    
    class node{
        public:
            int key;
            int val;
            node *next;
            node *prev;
            node(int k, int v){
                key = k, val= v;
            }
    };
    
    node* head = new node(-1,-1);
    node* tail = new node(-1,-1);
    
    unordered_map <int, node*> hash;
    int _capacity;
    
    LRUCache(int capacity) {
        _capacity = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    void addNode(node* newNode){
        // add to tail
        node* temp = head->next;
        head->next = newNode;
        newNode->prev = head;
        newNode->next = temp;
        temp->prev = newNode;
    }
    
    void deleteNode(node* delNode){
        node* delPrev = delNode->prev;
        node* delNext = delNode->next;
        delPrev->next = delNext;
        delNext->prev = delPrev;
        
        //delete delNode;
    }
    
    int get(int key) {
        // move to tail
        if(hash.find(key)!= hash.end()){
            node* retNode = hash[key];
            int ret = retNode->val;
            // move to front
            hash.erase(key);
            deleteNode(retNode); 
            addNode(retNode);
            hash[key] = retNode;
            return ret;
            
        }
        else return -1; 
    }
    
    void put(int key, int value) {
        if (hash.find(key) != hash.end()){
            node* existing = hash[key];
            hash.erase(key);
            deleteNode(existing);
        }
        if(hash.size() == _capacity){
            hash.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        node* newNode = new node(key, value);
        addNode(newNode);
        hash[key] = head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
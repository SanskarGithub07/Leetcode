#include<bits/stdc++.h>
using namespace std;

class TrieNode{
    public:
    char data;
    TrieNode * children[26];
    bool isTerminal;

    TrieNode(char element){
        this->data = element;
        for(int i = 0 ; i < 26 ; i++){
            this->children[i] = NULL;
        }
        this->isTerminal = false;
    }
};

class Trie {
public:
    TrieNode * root;
    Trie() {
       root = new TrieNode('\0');
    }

    void insertHelper(TrieNode * root, string word){
        if(word.length() == 0){
            root->isTerminal = true;
            return;
        }

        int index = word[0] - 'a';
        TrieNode * child;

        if(root->children[index] != NULL){
            child = root->children[index];
        }
        else{
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        insertHelper(child, word.substr(1));
    }

    void insert(string word) {
        insertHelper(root, word);
        return;
    }

    bool searchHelper(TrieNode * root, string word){
        if(word.length() == 0){
            return root->isTerminal;
        }

        int index = word[0] - 'a';
        TrieNode * child;

        if(root->children[index] != NULL){
            child = root->children[index];
        }
        else{
            return false;
        }

        return searchHelper(child, word.substr(1));
    }

    bool search(string word) {
        return searchHelper(root, word);
    }
    
    bool startsWithHelper(TrieNode * root, string prefix){
        if(prefix.length() == 0){
            return true;
        }

        int index = prefix[0] - 'a';
        TrieNode * child;

        if(root->children[index] != NULL){
            child = root->children[index];
        }
        else{
            return false;
        }

        return startsWithHelper(child, prefix.substr(1));
    }

    bool startsWith(string prefix) {
        return startsWithHelper(root, prefix);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
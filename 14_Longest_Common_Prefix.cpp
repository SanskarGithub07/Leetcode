#include<bits/stdc++.h>
using namespace std;

class TrieNode{
    public:
        char data;
        TrieNode * children[26];
        bool isTerminal;
        int childCount;

        TrieNode(char ch){  
            this->data = ch;
            for(int  i = 0 ; i < 26 ; i++){
                this->children[i] = NULL;       
            }
            this->isTerminal = false;
            this->childCount = 0;
        }
};

class Solution {
public:
    void insertIntoTrie(TrieNode * root, string letter){
        //base case
        if(letter.length() == 0){
            root->isTerminal = true;
            return;
        }

        TrieNode * child;
        int index = letter[0] - 'a';
        if(root->children[index] != NULL){
            child = root->children[index];
        }
        else{
            child = new TrieNode(letter[0]);
            root->children[index] = child;
            root->childCount++;
        }

        insertIntoTrie(child, letter.substr(1));
    }

    string longestCommonPrefix(vector<string>& strs) {
        TrieNode * root = new TrieNode('\0');

        for(auto letter : strs){
            if(letter == ""){
                return letter;
            }
            insertIntoTrie(root, letter);
        } 

        string ans = "";
        
        for(int i = 0 ; i < strs[0].size() ; i++){
            if(root->childCount == 1){
                ans += strs[0][i];
                int index = strs[0][i] - 'a';
                root = root->children[index];
            }
            else{
                break;
            }

            if(root->isTerminal){
                break;
            }
        }

        return ans;
    }
};
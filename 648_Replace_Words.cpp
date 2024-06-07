#include<bits/stdc++.h>
using namespace std;

#define TOTAL_NUMBER_ALPHABETS 26

class TrieNode{
    public:
    char data;
    TrieNode * children[TOTAL_NUMBER_ALPHABETS];
    bool isTerminal;

    TrieNode(char ch){
        this->data = ch;
        for(int i = 0 ; i < 26 ; i++){
            this->children[i] = NULL;
        }
        this->isTerminal = false;
    }
};

class Solution {
public:
    bool findShortestRoot(TrieNode * root, string word, string &ans){  
         if(root->isTerminal){
            return true;
        }

        if(word.length() == 0){
            return root->isTerminal;
        }

        TrieNode * child;
        int index = word[0] - 'a';

        if(root->children[index] != NULL){
            child = root->children[index];
            ans += child->data;
        }
        else{
            return false;
        }

        return findShortestRoot(child, word.substr(1), ans);
    }

    void insertIntoTrie(TrieNode * root, string word){
        if(word.length() == 0){
            root->isTerminal = true;
            return;
        }

        TrieNode * child;
        int index = word[0] - 'a';

        if(root->children[index] != NULL){
            child = root->children[index];
        }
        else{
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        insertIntoTrie(child, word.substr(1));
    }

    string replaceWords(vector<string>& dictionary, string sentence){
        vector<string> wordArray;
        TrieNode * root = new TrieNode('\0');
        for(auto word : dictionary){
            insertIntoTrie(root, word);
        }

        string temp = "";
        for(int i = 0 ; i < sentence.size() ; i++){
            if(sentence[i] == ' '){
                wordArray.push_back(temp);
                temp = "";
            }else{
                temp += sentence[i];
            }
        }
        wordArray.push_back(temp);

        for(int i = 0 ; i < wordArray.size() ; i++){
            string word = wordArray[i];
            string ans = "";
            if(findShortestRoot(root, word, ans)){
                wordArray[i] = ans;
            }
            else{
                wordArray[i] = word;
            }
        }

        string ans = "";
        for(int i = 0 ; i < wordArray.size() ; i++){
            ans += wordArray[i];
            if(i != wordArray.size() - 1){
               ans += " ";
            }
        }

        return ans;
    }
};
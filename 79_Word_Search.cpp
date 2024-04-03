#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool isSafe(vector<vector<char>>& board, int i, int j){
        if((i >= 0 && i < board.size()) && (j >= 0 && j < board[i].size())){
            return true;
        }
        return false;
    }

    bool checkIfExists(vector<vector<char>>& board, string& word, int i, int j, int wordIndex){
        if(wordIndex == word.length()){
            return true;
        }

        if(!isSafe(board, i, j) || board[i][j] != word[wordIndex]){
            return false;
        }

        char temp = board[i][j];
        board[i][j] = ' ';

        bool found = checkIfExists(board, word, i, j + 1, wordIndex + 1) || 
        checkIfExists(board, word, i + 1, j, wordIndex + 1) || 
        checkIfExists(board, word, i, j - 1, wordIndex + 1)|| 
        checkIfExists(board, word, i - 1, j, wordIndex + 1);

        board[i][j] = temp;

        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {
        for(int i = 0 ; i < board.size() ; i++){
            for(int j = 0 ; j < board[i].size() ; j++){
                if(word[0] == board[i][j] && checkIfExists(board, word, i, j, 0)){
                    return true;
                }
            }
        }

        return false;
    }
};
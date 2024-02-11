#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkRow(vector<vector<char>> &board, int row){
        unordered_set<char> st;

        for(int i = 0 ; i < board[row].size() ; i++){
            if(st.find(board[row][i]) != st.end()){
                return false;
            }
            else if(board[row][i] != '.'){
                st.insert(board[row][i]);
            }
        }

        return true;
    }

    bool checkColumn(vector<vector<char>> &board, int column){
        unordered_set<char> st;

        for(int i = 0 ; i < board.size() ; i++){
            if(st.find(board[i][column]) != st.end()){
                return false;
            }
            else if(board[i][column] != '.'){
                st.insert(board[i][column]);
            }
        }

        return true;
    }

    bool checkGrid(vector<vector<char>> &board, int row, int column){
        unordered_set<char> st;

        for(int i = 0 ; i < 3 ; i++){
            for(int j = 0 ; j < 3 ; j++){
                int current = board[i + row][j + column];

                if(st.find(current) != st.end()){
                    return false;
                }
                else if(current != '.'){
                    st.insert(current);
                }
            }   
        }

        return true;
    }

    bool isValidElement(vector<vector<char>> &board, int row, int column){
        return checkRow(board, row) && checkColumn(board, column) && checkGrid(board, row - row % 3, column - column % 3);
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i = 0 ; i < board.size() ; i++){
            for(int j = 0 ; j < board[i].size() ; j++){
                if(!isValidElement(board, i, j)){
                    return false;
                }
            }
        }

        return true;
    }
};
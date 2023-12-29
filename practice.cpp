#include<bits/stdc++.h>
using namespace std;

// Celebrity Problem
int celebrity(vector<vector<int>> &M, int n){
    stack<int> stk;
    for(int i = 0 ; i < n ; i++){
        stk.push(i);
    }

    while(stk.size() != 1){
        int A = stk.top();
        stk.pop();
        int B = stk.top();
        stk.pop(); 

        if(M[A][B]){
            stk.push(B);
        }
        else if(M[B][A]){
            stk.push(A);
        }
    }

    int potentialCelebrity = stk.top();
    stk.pop();

    bool rowCheck = true;
    for(int i = 0 ; i < n ; i++){
        if(M[potentialCelebrity][i] == 1){
            rowCheck = false;
            return -1;
        }
    }

    bool columnCheck = true;
    for(int row = 0 ; row < n ; row++){
        if(potentialCelebrity != row){
            if(M[row][potentialCelebrity] == 0){
                columnCheck = false;
                return -1;
            }
        }
    }

    if(rowCheck && columnCheck){
        return potentialCelebrity;
    }

    return -1;
}

int main(){
    vector<vector<int>> M ={{0, 1, 0}, {0, 0, 0}, {0, 1, 0}};
    int n = 3;

    cout << celebrity(M, n) << endl; 
}
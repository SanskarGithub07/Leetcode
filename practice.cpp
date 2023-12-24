#include<bits/stdc++.h>
using namespace std;

vector<int> nextSmallerElement(vector<int> &arr){
    stack<int> stk;
    stk.push(-1);
    for(int i = arr.size() - 1 ; i >= 0 ; i--){
        int val = stk.top();
        if(arr[i] > val){
            stk.push(arr[i]);
            arr[i] = val;
        }
        else{
            while(stk.top() >= arr[i]){
                stk.pop();
            }
            int newTopVal = stk.top();
            stk.push(arr[i]);
            arr[i] = newTopVal;
        }
    }

    return arr;
}
int main(){
    vector<int> arr = {2, 1, 4, 3};
    arr = nextSmallerElement(arr);
    for(int i = 0 ; i < arr.size() ; i++){
        cout << arr[i] << " " ;
    }

    return 0;
}
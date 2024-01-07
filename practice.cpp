#include<bits/stdc++.h>
using namespace std;

// Time Complexity: O((m + n)log (m + n))
// Space Complexity: O(m + n) 

void heapify(vector<int> &mergedHeap, int n, int i){
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if(left < n && mergedHeap[left] > mergedHeap[largest]){
        largest = left;
    }

    if(right < n && mergedHeap[right] > mergedHeap[largest]){
        largest = right;
    }

    if(largest != i){
        swap(mergedHeap[largest], mergedHeap[i]);
        heapify(mergedHeap, n, largest);
    }

    return;
}

void buildMaxHeap(vector<int> &mergedHeap, int n){
    for(int i = n / 2 - 1 ; i >= 0 ; i--){
        heapify(mergedHeap, n, i);
    }
}

vector<int> merge2BMH(vector<int> &MH1, vector<int> &MH2){
    //Step1: Merge both the vectors into a single vector
    vector<int> mergedHeap;

    for(int i = 0 ; i < MH1.size() ; i++){
        mergedHeap.push_back(MH1[i]);
    }

    for(int i = 0 ; i < MH2.size() ; i++){
        mergedHeap.push_back(MH2[i]);
    }

    //Step2: Use buildMaxHeap and heapify functions to get the final mergedHeap.
    int n = mergedHeap.size();
    buildMaxHeap(mergedHeap, n);

    return mergedHeap;
}

int main(){
    vector<int> MH1 = {10, 5, 6, 2};
    vector<int> MH2 = {12, 7, 9};

    vector<int> ans = merge2BMH(MH1, MH2);

    for(int i = 0 ; i < ans.size() ; i++){
        cout << ans[i] << " ";
    }cout << endl;

    return 0;
}
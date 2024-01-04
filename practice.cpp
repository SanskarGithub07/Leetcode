#include<bits/stdc++.h>
using namespace std;

void heapify(vector<int> &arr, int n, int i){
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if(left < n && arr[left] > arr[largest]){
        largest = left;
    }

    if(right < n && arr[right] > arr[largest]){
        largest = right;
    }

    if(largest != i){
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }

    return;
}

void heapSort(vector<int> &arr, int n){

    for(int i = n / 2 - 1 ; i >= 0 ; i--){
        heapify(arr, n, i);
    }

    for(int i = 0 ; i < arr.size() ; i++){
        swap(arr[0], arr[n - 1]);
        n--;
        heapify(arr, n, 0);
    }
}

int main(){
    vector<int> arr = {6,2,11,3,4,1,0};
    int n = arr.size();

    heapSort(arr, n);

    for(int i = 0 ; i < arr.size() ; i++){
        cout << arr[i] << " ";
    }cout << endl;

    return 0;
}
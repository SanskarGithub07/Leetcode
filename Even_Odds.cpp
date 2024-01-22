#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    vector<int> ans(n, -1);

    int left = 0;
    int right;
    if(n % 2 == 0){
        right = n / 2;
    }
    else{
        right = n / 2 + 1;
    }

    int start = 1;
    while(right < n){
        ans[left] = start;
        ans[right] = start + 1;
        start += 2;
        left++;
        right++;

        if(left == k){
            cout << ans[left - 1];
            break;
        }
        else if(right == k){
            cout << ans[right - 1];
            break;
        }
    }

    return 0;
}
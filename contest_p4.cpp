#include<bits/stdc++.h>
using namespace std;

int main(){
    int testcases;
    cin >> testcases;

    while(testcases--){
        int n, m;
        cin >> n >> m;
        vector<int> arr1(n, -1);
        vector<int> arr2(m, -1);
        int temp;
        for(int i = 0 ; i < n ; i++){
            cin >> temp;
            arr1.push_back(temp);
        }

        temp = -1;
        for(int i = 0 ; i < m ; i++){
            cin >> temp;
            arr2.push_back(temp);
        }

        int ans = 0;
        for(int i = 0 ; i < arr1.size() ; i++){
            int maxVal = 0;
            for(int j = 0 ; j < arr2.size() ; j++){
               if(maxVal > (arr2[j] - arr1[i]) && arr2[j] !=){
                maxVal = abs(arr2[j] - arr1[i]);
                arr2[j] = -1;
               }
            }
            ans += maxVal;
        }

        cout << ans << endl;
    }
}
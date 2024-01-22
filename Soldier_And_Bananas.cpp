#include<bits/stdc++.h>
using namespace std;

int main(){
    int k, n, w;
    cin >> k >> n >> w;

    int cost = k * ((w * (w + 1)) / 2);
    int moneyToBorrow = 0;
    if(cost - n < 0){
        cout << moneyToBorrow;
    }
    else{
        moneyToBorrow = cost - n;
        cout << moneyToBorrow;
    }

    return 0;
}
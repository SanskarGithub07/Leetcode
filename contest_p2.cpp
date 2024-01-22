#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;

    while(t--){
        int size;
        cin >> size;

        string firstString;
        cin >> firstString;

        string secondString;
        cin >> secondString;

        int i = 0, j = 0;
        int a = 0, b = 0;

        while(i < firstString.length()){
            if((firstString[i] != secondString[j]) && firstString[i] == '1'){
                a++;
            }
            else if((firstString[i] != secondString[j]) && secondString[j] == '1'){
                b++;
            }
            i++;
            j++;
        }

        cout << max(a, b) << endl;
    }
}
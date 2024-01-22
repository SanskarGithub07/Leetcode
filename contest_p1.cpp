#include<bits/stdc++.h>
using namespace std;

int main()
{
    int testcases;
    cin >> testcases;

    int x_cors[2];
    int y_cors[2];

    for(int i = 0 ; i < testcases ; i++){
        int temp=0;
        cin >> x_cors[0];
        cin >> y_cors[0];

        for(int j = 0 ; j < 3 ; j++)
        {
            cin>>temp;
            if(temp != x_cors[0])
            {
                x_cors[1] = temp;
            }
            cin>>temp;
            if(temp != y_cors[0])
            {
                y_cors[1] = temp;
            }
        }

        int x = x_cors[1]-x_cors[0];
        int y = y_cors[1]-y_cors[0];
        int result = abs(x * y);
        cout << result << endl;
        
    }
}
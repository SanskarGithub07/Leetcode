/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

#include <bits/stdc++.h>
using namespace std;

//Sample testcase for 7
int guessedVal = 7;

class Solution {
public:
    int guessNumber(int n) {
        int left = 1;
        int right = n;
        int ans = 0;
        while(left <= right){
            int mid = (right - left) / 2 + left;
            if(guess(mid) == 0){
                ans = mid;
                break;
            }

            if(guess(mid) == -1){
                right = mid - 1;
            }
            else if(guess(mid) == 1) {
                left = mid + 1;
            }
        }

        return ans;
    }
};

int guess(int k){
    if(k < guessedVal){
        return 1;
    }
    else if(k > guessedVal){
        return -1;
    }

    return 0;
}
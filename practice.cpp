#include<bits/stdc++.h>
using namespace std;

class nStacks {
    public:
        int *arr;
        int *top;
        int *next;
        int freeSpot;

        nStacks(int N, int S){
            this->arr = new int[S];
            this->top = new int[N];
            this->next = new int[S];
            this->freeSpot = 0;

            for(int i = 0 ; i < N ; i++){
                this->top[i] = -1;
            }

            for(int i = 0 ; i < S ; i++){
                this->next[i] = i + 1;
            }
            this->next[S - 1] = -1;
        }

        bool push(int x, int m){
            if(freeSpot == -1){
                return false;
            }

            //find index
            int index = freeSpot;

            //insert element into array
            arr[index] = x;

            //update freeSpot
            freeSpot = next[index];

            //update next array because element has been inserted
            next[index] = top[m - 1];

            //update top
            top[m - 1] = index;

            return true;
        }

        int pop(int m){

            //Check for the stack being empty
            if(top[m - 1] == -1){
                return -1;
            }

            //Write everything in reverse order.
            int index = top[m - 1];

            top[m - 1] = next[index];

            next[index] = freeSpot;

            freeSpot = index;

            return arr[index];
        }
};

int main(){
    nStacks * nStks = new nStacks(3, 6);
    cout << nStks->push(10, 1) << endl;
    cout << nStks->push(20, 1) << endl;
    cout << nStks->push(30, 2) << endl;
    cout << nStks->pop(1) << endl;
    cout << nStks->pop(2) << endl;

    return 0;
}
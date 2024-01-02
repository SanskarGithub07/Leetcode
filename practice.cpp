#include<bits/stdc++.h>
using namespace std;

class Heap{
    public:
        int * heap;
        int size;
        int capacity;
        Heap(int capacity){
            this->capacity = capacity;
            this->heap = new int[this->capacity];
            this->size = 0;
        }

        void insert(int element){
            size++;
            int index = size;
            heap[index] = element;

            while(index > 1){
                int parent = index / 2;

                if(heap[parent] < heap[index]){
                    swap(heap[parent], heap[index]);
                    index = parent;
                }
                else{
                    return;
                }
            }
        }

        void print(){
            for(int i = 1 ; i <= size ; i++){
                cout << heap[i];
            }cout << endl;
        }
};

int main(){
    Heap * hp = new Heap(10);
    hp->insert(50);
    hp->insert(55);
    hp->insert(53);
    hp->insert(52);
    hp->insert(54);
    hp->print();
}
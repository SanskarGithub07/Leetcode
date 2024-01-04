#include<bits/stdc++.h>
using namespace std;

class Heap{
    public:
        int * heap;
        int size;
        int capacity;
        Heap(int capacity){ //Constructor for the heap
            this->capacity = capacity;
            this->heap = new int[this->capacity];
            this->size = 0;
        }

        void insert(int element){ //Insertion into the heap.
        //Increasing size and inserting element at the end.
            size++;
            int index = size;
            heap[index] = element;

            while(index > 1){ //Comparing with parent and swapping accordingly
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

        void remove(){ //Deletion from a heap.
        //Checking for size == 0 which means heap is empty
            if(size == 0){
                cout << "Nothing to delete as no element is present" << endl;
                return;
            }

            //Swapping and deleting from the heap
            heap[1] = heap[size];
            size--;

            // Rectifying the position of the swapped root
            int i = 1;
            while(i < size){
                int rightIndex = 2 * i;
                int leftIndex = 2 * i + 1;

                if(leftIndex < size && heap[leftIndex] < heap[i]){
                    swap(heap[leftIndex], heap[i]);
                    i = leftIndex;
                }
                else if(rightIndex < size && heap[rightIndex] < heap[i]){
                    swap(heap[rightIndex], heap[i]);
                    i = rightIndex;
                }
                else{
                    return;
                }
            }
        }

        void print(){ //Function to print the heap.
            for(int i = 1 ; i <= size ; i++){
                cout << heap[i] << " ";
            }cout << endl;
        }
};

void heapify(int arr[], int n, int i){ // This function sets the value of the root of one sub heap of the og heap.

    //Step 1: Calculate indicies for left right and largest.
    int largest = i;
    int left = 2 * i;
    int right = 2 * i + 1;

    //Step 2: Check for left and right child if they are larger than largest
    if(left < n && arr[left] > arr[largest]){
        largest = left;
    } 

    if(right < n && arr[right] > arr[largest]){
        largest = right;
    }

    //If largest is not equal to i swap and call heapify for largest.
    if(largest != i){
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

int main(){
    Heap * hp = new Heap(10);
    hp->insert(50);
    hp->insert(55);
    hp->insert(53);
    hp->insert(52);
    hp->insert(54);
    hp->print();

    hp->remove();

    hp->print();

    int arr[6] = {-1, 54, 53, 55, 52, 50};
    int n = 5;

    for(int i = n / 2 ; i > 0 ; i--){
        heapify(arr, n, i);
    }

    cout << "Printing the array: " << endl;

    for(int i = 1 ; i <= n ; i++){
        cout << arr[i] << " ";
    }cout << endl;

    return 0;
}
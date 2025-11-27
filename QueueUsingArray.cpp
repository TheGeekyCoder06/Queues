#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class QueueUsingArray {
    vector<int> arr;
    int frontIdx , rearIdx , capacity , currentSize;

    public:
        QueueUsingArray(int size){
            arr.resize(size);
            capacity = size;
            frontIdx = 0;
            rearIdx = -1;
            currentSize = 0;
        }
        bool enqueue(int data){
            if(currentSize == capacity){
                cout<<"Queue is full" << endl;
                return false;
            }
            rearIdx = (rearIdx + 1) % capacity;
            arr[rearIdx] = data;
            currentSize++;
            return true;
        }
        int dequeue(){
            if(currentSize == 0){
                cout << "Queue is empty" << endl;
                return -1;
            }
            int data = arr[frontIdx];
            frontIdx = (frontIdx + 1) % capacity;
            currentSize--;
            return data;
        }

        bool isEmpty(){
            return currentSize == 0;
        }
        int size(){
            return currentSize;
        }
        int front(){
            if(currentSize == 0){
                cout<<"Queue is empty" << endl;
                return -1;
            }
            return arr[frontIdx];
        }
};

int main(){
    QueueUsingArray q(5);
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    q.enqueue(6); // Queue is full

    cout << "Front element: " << q.front() << endl; // 1
    cout << "Queue size: " << q.size() << endl; // 5

    while(!q.isEmpty()){
        cout << q.dequeue() << " ";
    }
    cout << endl;

    q.dequeue(); // Queue is empty

    return 0;
}

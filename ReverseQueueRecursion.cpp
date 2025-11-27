#include<iostream>
#include<queue>
using namespace std;

void reverseQueue(queue<int> &q){
    // base case 
    if(q.empty()) return;

    int frontElem = q.front();
    q.pop();
    reverseQueue(q);
    q.push(frontElem);
}

int main(){
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    reverseQueue(q);

    cout << "Front element: " << q.front() << endl;
    cout << "Queue size: " << q.size() << endl;
    while(!q.empty()){
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
    return 0;
}

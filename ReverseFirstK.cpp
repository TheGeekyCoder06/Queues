#include<iostream>
#include<queue>
#include<stack>
using namespace std;

void reverseFirstK(queue<int> &q, int k){
    if(k <= 0 || q.empty()) return;

    stack<int> st;

    for(int i=0; i<k; i++){
        st.push(q.front());
        q.pop();
    }

    while(!st.empty()){
        q.push(st.top());
        st.pop();
    }

    int remaining = q.size() - k;
    while(remaining--){
        q.push(q.front());
        q.pop();
    }
}

int main(){
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    int k = 3;
    reverseFirstK(q, k);

    cout << "Front element: " << q.front() << endl;
    cout << "Queue size: " << q.size() << endl;
    while(!q.empty()){
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
    return 0;
}
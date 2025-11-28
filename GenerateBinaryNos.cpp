#include<queue>
#include<iostream>
using namespace std;

int main(){
    int n;
    cin >>n;
    queue<string> q;
    vector<string> ans;
    q.push("1");
    for(int i=0; i<n; i++){
        string s= q.front();
        q.pop();
        ans.push_back(s);

        q.push(s + "0");
        q.push(s + "1");
    }
    for(string str : ans){
        cout << str << " ";
    }
    cout<<endl;
}
#include <iostream>
#include <stack>
#include <queue>
using namespace std;

string FirstNonRepeating(string s)
{
    vector<int> freq(26, 0);
    queue<char> q;
    string result;
    for(char ch : s){
        freq[ch - 'a']++;
        q.push(ch);

        while(!q.empty() && freq[q.front() - 'a'] > 1) q.pop();
        if(q.empty()) result += '#';
        else result += q.front();
    }
    return result;
}

int main(){
    string s = "aabc";
    string res = FirstNonRepeating(s);
    cout << "First non-repeating characters: " << res << endl;
    return 0;
}

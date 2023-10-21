#include <bits/stdc++.h>
using namespace std;

string s;
stack<char> st;

int main() {
    cin >> s;
    for (char& c : s) {
        if (!st.empty() && st.top() == 'S' && c == 'T')
            st.pop();
        else
            st.push(c);
    }
    cout << st.size();
}
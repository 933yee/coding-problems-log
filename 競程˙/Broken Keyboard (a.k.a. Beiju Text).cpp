#include <bits/stdc++.h>
using namespace std;

string s, cur;
vector<string> v;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    while (cin >> s) {
        v.clear();
        v.resize(1);
        cur.clear();
        bool isForward = true;
        for (char& c : s) {
            if (c == '[') {
                isForward = false;
                if (!cur.empty()) {
                    v.emplace_back(cur);
                    cur.clear();
                }
            } else if (c == ']') {
                isForward = true;
            } else if (isForward)
                v[0].push_back(c);
            else
                cur.push_back(c);
        }
        cout << cur;
        for (auto it = v.rbegin(); it != v.rend(); ++it)
            cout << *it;
        cout << '\n';
    }
}
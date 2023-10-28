#include <bits/stdc++.h>
using namespace std;

int t, n;
string s;
vector<int> tb = {10, 1, 2, 3, 4, 5, 6, 7, 8, 9};
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--) {
        int cnt = 0, prev = 1;
        cin >> s;
        for (char& c : s) {
            cnt += abs(tb[c - '0'] - tb[prev]) + 1;
            prev = c - '0';
        }
        cout << cnt << '\n';
    }
}
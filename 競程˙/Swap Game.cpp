#include <bits/stdc++.h>
using namespace std;

string cur, ans = "123456789";
unordered_set<string> seen;
queue<string> q;
int step = 0, x;

void SWAP(int x, int y) {
    swap(cur[x], cur[y]);
    if (seen.find(cur) == seen.end()) {
        q.push(cur);
        seen.insert(cur);
    }
    swap(cur[x], cur[y]);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for (int i = 0; i < 9; i++) {
        cin >> x;
        cur += x + '0';
    }
    q.push(cur);
    seen.insert(cur);
    while (!q.empty()) {
        // cout << step << '\n';
        for (int cnt = q.size(); cnt--;) {
            cur = q.front();
            q.pop();
            if (cur == ans) {
                cout << step;
                return 0;
            }
            for (int i = 0; i < 9; i += 3) {
                SWAP(i, i + 1);
                SWAP(i + 1, i + 2);
            }
            for (int i = 0; i < 3; i++) {
                SWAP(i, i + 3);
                SWAP(i + 3, i + 6);
            }
        }
        step++;
    }
}

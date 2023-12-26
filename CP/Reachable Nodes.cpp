#include <bits/stdc++.h>
using namespace std;

int n, m, a, b;
const int mx = 5e4 + 5;
vector<vector<int>> G(mx);
vector<int> in(mx);
bitset<mx> ans[mx];
queue<int> q;

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        G[b].push_back(a);
        in[a]++;
    }
    for (int i = 1; i <= n; i++) {
        if (in[i] == 0) {
            q.push(i);
            ans[i].set(i);
        }
    }
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (int& i : G[cur]) {
            ans[i] |= ans[cur];
            in[i]--;
            if (in[i] == 0) {
                q.push(i);
                ans[i].set(i);
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << ans[i].count() << ' ';
    }
}
#include <bits/stdc++.h>
using namespace std;

int n, m, a, b, mx = 1e5 + 5;
vector<vector<int>> G(mx);
vector<int> in(mx), ans;
queue<int> q;

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        G[a].push_back(b);
        in[b]++;
    }
    for (int i = 1; i <= n; i++)
        if (in[i] == 0)
            q.push(i);

    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        ans.push_back(cur);
        for (int& i : G[cur]) {
            in[i]--;
            if (in[i] == 0) {
                q.push(i);
            }
        }
    }
    if (ans.size() == n) {
        for (int& i : ans) cout << i << ' ';
    } else
        cout << "IMPOSSIBLE";
}
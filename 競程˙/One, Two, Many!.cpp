#include <bits/stdc++.h>
using namespace std;

int n, m, a, b, mx = 1e5 + 5;
vector<vector<int>> G(mx);
vector<int> ans(mx);

bool dfs(int cur, int label, int parent) {
    ans[cur] = label;
    for (int& i : G[cur]) {
        int nextLabel = (label == 1 ? 2 : 1);
        if (!ans[i]) {
            if (!dfs(i, nextLabel, cur))
                return false;
        } else if (i != parent && ans[i] == label)
            return false;
    }
    return true;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    for (int i = 1; i <= n; i++) {
        if (!ans[i])
            if (!dfs(i, 1, -1)) {
                cout << "MANY";
                return 0;
            }
    }

    for (int i = 1; i <= n; i++) cout << ans[i] << ' ';
}
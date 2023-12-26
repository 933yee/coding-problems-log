#include <bits/stdc++.h>
using namespace std;

int n, a, b, mx = 2e5 + 5, ans = -1;
vector<vector<int>> v(mx);
vector<int> sz(mx);

void dfs(int u, int parent = -1) {
    int mx_child = 0;
    for (int& i : v[u]) {
        if (i == parent) continue;
        dfs(i, u);
        sz[u] += sz[i] + 1;
        mx_child = max(mx_child, sz[i] + 1);
    }
    mx_child = max(mx_child, n - sz[u] - 1);
    if (mx_child <= n / 2) ans = u;
}

int main() {
    cin >> n;
    for (int i = 1; i < n; i++) {
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    dfs(1);
    cout << ans;
}
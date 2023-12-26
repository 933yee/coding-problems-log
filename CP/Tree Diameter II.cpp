#include <bits/stdc++.h>
using namespace std;

int n, mx = 2e5 + 1;
vector<vector<int>> v(mx);
vector<long long> ans(mx), cnt(mx);

void dfs(int cur, int parent, int depth) {
    ans[1] += depth;
    cnt[cur] = 1;

    for (int& u : v[cur]) {
        if (parent == u) continue;
        dfs(u, cur, depth + 1);
        cnt[cur] += cnt[u];
    }
}

void dfs2(int cur, int parent) {
    for (int& u : v[cur]) {
        if (parent == u) continue;
        ans[u] = ans[cur] + (n - cnt[u]) - (cnt[u]);
        dfs2(u, cur);
    }
}

int main() {
    cin >> n;
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    dfs(1, -1, 0);
    dfs2(1, -1);
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << ' ';
    }
}

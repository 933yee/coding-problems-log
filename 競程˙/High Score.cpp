#include <bits/stdc++.h>
using namespace std;

int n, m, a, b, x, mx = 3000;
long long ans;
vector<vector<pair<int, long long>>> G(mx);
vector<long long> dist(mx, -LONG_LONG_MAX / 2);

bool dfs(int cur, vector<bool>& seen) {
    if (cur == n) return true;
    seen[cur] = true;
    for (auto& i : G[cur]) {
        if (!seen[i.first])
            if (dfs(i.first, seen))
                return true;
    }
    return false;
}

int main() {
    cin >> n >> m;
    dist[1] = 0;

    for (int i = 0; i < m; i++) {
        cin >> a >> b >> x;
        G[a].push_back({b, x});
    }

    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= n; j++) {
            if (dist[j] != -LONG_LONG_MAX / 2) {
                for (auto& k : G[j]) {
                    if (dist[k.first] < dist[j] + k.second) {
                        dist[k.first] = dist[j] + k.second;
                    }
                }
            }
        }
    }

    for (int j = 1; j <= n; j++) {
        if (dist[j] != -LONG_LONG_MAX / 2) {
            for (auto& k : G[j]) {
                if (dist[k.first] < dist[j] + k.second) {
                    vector<bool> seen(n + 1);
                    if (dfs(k.first, seen)) {
                        cout << -1;
                        return 0;
                    }
                }
            }
        }
    }
    cout << dist[n];
}
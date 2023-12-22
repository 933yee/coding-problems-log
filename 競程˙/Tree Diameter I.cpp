#include <bits/stdc++.h>
using namespace std;

int n, mx = 2e5 + 1;
vector<vector<int>> v(mx);
vector<int> p(mx);
vector<pair<int, int>> len(mx);

void dfs(int cur, int parent) {
    for (int& u : v[cur]) {
        if (parent == u) continue;
        dfs(u, cur);
        if (len[u].first + 1 > len[cur].first) {
            len[cur].second = len[cur].first;
            len[cur].first = len[u].first + 1;
            p[cur] = u;
        } else if (len[u].first + 1 > len[cur].second) {
            len[cur].second = len[u].first + 1;
        }
    }
}

void dfs2(int cur, int parent) {
    for (int& u : v[cur]) {
        if (parent == u) continue;
        if (p[cur] == u) {
            if (len[cur].second + 1 > len[u].first) {
                len[u].second = len[u].first;
                len[u].first = len[cur].second + 1;
                p[u] = cur;
            } else if (len[cur].second + 1 > len[u].second) {
                len[u].second = len[cur].second + 1;
            }
        } else {
            if (len[cur].first + 1 > len[u].first) {
                len[u].second = len[u].first;
                len[u].first = len[cur].first + 1;
                p[u] = cur;
            } else if (len[cur].first + 1 > len[u].second) {
                len[u].second = len[cur].first + 1;
            }
        }
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
    dfs(1, -1);
    dfs2(1, -1);
    for (int i = 1; i <= n; i++) {
        cout << len[i].first << ' ';
    }
}

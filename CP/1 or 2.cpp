#include <bits/stdc++.h>
using namespace std;

int N, M, mx = 1e5 + 5, ans;
vector<vector<int>> v(mx);
vector<int> seen(mx);

void dfs(int cur) {
    for (int& i : v[cur]) {
        if (!seen[i]) {
            seen[i] = true;
            dfs(i);
        }
    }
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    for (int i = 1; i <= N; i++) {
        if (!seen[i]) {
            dfs(i);
            ans++;
        }
    }
    cout << ans;
}
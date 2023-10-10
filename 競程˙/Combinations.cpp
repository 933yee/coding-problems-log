#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> v, ans;

void dfs(int cnt, int idx) {
    if (cnt == m) {
        for (int& i : ans) cout << i << ' ';
        cout << '\n';
        return;
    }
    for (int i = idx; i < n; i++) {
        ans.emplace_back(v[i]);
        dfs(cnt + 1, i + 1);
        ans.pop_back();
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    v.resize(n);
    for (int& i : v) cin >> i;
    dfs(0, 0);
}
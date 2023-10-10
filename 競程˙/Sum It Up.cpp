#include <bits/stdc++.h>
using namespace std;

int t, n;
vector<int> v, cur;
vector<vector<int>> ans;

void dfs(int idx, int sum) {
    if (sum == t) {
        ans.emplace_back(cur);
        return;
    }
    if (sum > t) return;
    bool seen[1005] = {};
    for (int i = idx; i < n; i++) {
        if (!seen[v[i]]) {
            seen[v[i]] = true;
            cur.emplace_back(v[i]);
            dfs(i + 1, sum + v[i]);
            cur.pop_back();
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    while (cin >> t >> n && t != 0 && n != 0) {
        v.clear();
        ans.clear();
        v.resize(n);
        for (int& i : v) cin >> i;
        sort(v.rbegin(), v.rend());
        dfs(0, 0);
        cout << "Sums of " << t << ":\n";
        for (int i = 0; i < ans.size(); i++) {
            for (int j = 0; j < ans[i].size(); j++) {
                cout << ans[i][j] << (j == ans[i].size() - 1 ? '\n' : '+');
            }
        }
        if (ans.empty())
            cout << "NONE\n";
    }
}
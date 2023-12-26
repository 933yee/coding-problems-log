#include <bits/stdc++.h>
using namespace std;

int n;
vector<pair<int, int>> ans;

void dfs(int cnt, int a, int b, int c) {
    if (cnt == n) {
        // cout << a << ' ' << c << '\n';
        ans.push_back({a, c});
        return;
    }
    dfs(cnt + 1, a, c, b);
    // cout << a << ' ' << c << '\n';
    ans.push_back({a, c});
    dfs(cnt + 1, b, a, c);
}

int main() {
    cin >> n;
    dfs(1, 1, 2, 3);
    cout << ans.size() << '\n';
    for (auto& i : ans) {
        cout << i.first << ' ' << i.second << '\n';
    }
}
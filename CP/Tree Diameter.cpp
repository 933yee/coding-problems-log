#include <bits/stdc++.h>
using namespace std;

int n, mx = 2e5 + 1;
vector<vector<int>> v(mx);
vector<int> level(mx);

void dfs(int a, int parent) {
    if (parent == -1)
        level[a] = 0;
    else
        level[a] = level[parent] + 1;
    for (int& i : v[a]) {
        if (i == parent) continue;
        dfs(i, a);
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
    int a = max_element(level.begin(), level.end()) - level.begin();
    dfs(a, -1);
    a = *max_element(level.begin(), level.end());
    cout << a << '\n';
}
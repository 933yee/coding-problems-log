#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> G(1e5 + 5);
vector<int> color(1e5 + 5);
vector<vector<long long>> dp(1e5 + 5, vector<long long>(2));
int M = 1e9 + 7;

long long dfs(int cur, int label, int parent) {
    if (dp[cur][label]) return dp[cur][label];
    long long ret = 1;
    if (label == 1) {
        for (int& i : G[cur]) {
            if (i == parent) continue;
            long long tmp = 0;
            tmp += dfs(i, 1, cur) % M;
            tmp += dfs(i, 0, cur) % M;
            ret *= tmp % M;
            ret %= M;
        }
    } else if (label == 0) {
        for (int& i : G[cur]) {
            if (i == parent) continue;
            long long tmp = 0;
            tmp += dfs(i, 1, cur) % M;
            ret *= tmp;
            ret %= M;
        }
    }
    return dp[cur][label] = ret % M;
}

int main() {
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    long long ans = 0;
    ans += (dfs(1, 1, -1) + dfs(1, 0, -1)) % M;

    cout << ans;
}

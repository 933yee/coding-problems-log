#include <bits/stdc++.h>
using namespace std;

int n, x;
vector<vector<long long>> dp(405, vector<long long>(405));
vector<long long> prefix(405);
long long ans;

long long dfs(int l, int r) {
    if (l == r) return 0;
    if (dp[l][r]) return dp[l][r];
    // if (l + 1 == r) return prefix[r] - prefix[l - 1];
    long long ret = LONG_LONG_MAX;
    for (int i = l; i < r; i++) {
        ret = min(ret, dfs(l, i) + dfs(i + 1, r) + prefix[r] - prefix[l - 1]);
    }
    return dp[l][r] = ret;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x;
        prefix[i] = prefix[i - 1] + x;
    }
    cout << dfs(1, n);
}
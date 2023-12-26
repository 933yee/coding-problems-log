#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> v, dp;

int main() {
    cin >> n;
    dp.resize(n + 1, vector<int>(3));
    for (int i = 0; i < n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        v.push_back({a, b, c});
    }
    for (int i = 0; i < n; i++) {
        dp[i + 1][0] = max(dp[i][1] + v[i][1], dp[i][2] + v[i][2]);
        dp[i + 1][1] = max(dp[i][0] + v[i][0], dp[i][2] + v[i][2]);
        dp[i + 1][2] = max(dp[i][0] + v[i][0], dp[i][1] + v[i][1]);
    }
    cout << max(dp[n][0], max(dp[n][1], dp[n][2]));
}
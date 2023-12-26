#include <bits/stdc++.h>
using namespace std;

string s, t;
vector<vector<int>> dp(3005, vector<int>(3005));
vector<vector<pair<int, int>>> idx(3005, vector<pair<int, int>>(3005));

int main() {
    cin >> s >> t;
    int n = s.size();
    int m = t.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (s[i] == t[j]) {
                dp[i + 1][j + 1] = dp[i][j] + 1;
                idx[i + 1][j + 1] = {i, j};
            } else if (dp[i][j + 1] > dp[i + 1][j]) {
                dp[i + 1][j + 1] = dp[i][j + 1];
                idx[i + 1][j + 1] = {i, j + 1};
            } else {
                dp[i + 1][j + 1] = dp[i + 1][j];
                idx[i + 1][j + 1] = {i + 1, j};
            }
        }
    }
    string ans;
    while (n > 0 || m > 0) {
        auto k = idx[n][m];
        if (k.first == n - 1 && k.second == m - 1) {
            ans += s[n - 1];
        }
        n = k.first;
        m = k.second;
    }
    reverse(ans.begin(), ans.end());
    cout << ans;
}
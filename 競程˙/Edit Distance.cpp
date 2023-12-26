#include <bits/stdc++.h>
using namespace std;

string s, t;
vector<vector<int>> dp(5005, vector<int>(5005));

int main() {
    cin >> s >> t;
    for (int i = 0; i < 5005; i++) {
        dp[i][0] = i;
        dp[0][i] = i;
    }
    for (int i = 1; i <= s.size(); i++) {
        for (int j = 1; j <= t.size(); j++) {
            if (s[i - 1] == t[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else
                dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
        }
    }
    cout << dp[s.size()][t.size()];
}
#include <bits/stdc++.h>
using namespace std;

int n, M = 1e9 + 7;
// vector<int> dp(505);
vector<vector<int>> dp(505, vector<int>(505 * 505 / 2));

int main() {
    cin >> n;
    int tar = (1 + n) * n / 2;
    if (tar & 1) {
        cout << 0;
        return 0;
    }
    tar /= 2;
    dp[0][0] = dp[1][1] = 1;
    for (int i = 2; i <= n; i++) {
        for (int j = 0; j <= tar; j++) {
            dp[i][j] = dp[i - 1][j] % M;
            if (j - i >= 0) {
                dp[i][j] += dp[i - 1][j - i];
                dp[i][j] %= M;
            }
        }
    }
    cout << dp[n][tar];
}
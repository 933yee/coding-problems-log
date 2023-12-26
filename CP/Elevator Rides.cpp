#include <bits/stdc++.h>
using namespace std;

int n, x;
vector<int> weights;
vector<int> dp((1 << 20) + 5, INT_MAX), last((1 << 20) + 5, INT_MAX);

int main() {
    cin >> n >> x;
    weights.resize(n);
    for (int& i : weights) cin >> i;

    last[0] = x;
    dp[0] = 0;
    for (int i = 1; i < (1 << n); i++) {
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                int a = i ^ (1 << j);
                if (last[a] + weights[j] <= x) {
                    if (dp[i] >= dp[a]) {
                        dp[i] = dp[a];
                        last[i] = min(last[i], last[a] + weights[j]);
                    }
                } else {
                    if (dp[i] > dp[a]) {
                        dp[i] = dp[a] + 1;
                        last[i] = min(last[i], weights[j]);
                    }
                }
            }
        }
    }
    cout << dp[(1 << n) - 1];
}
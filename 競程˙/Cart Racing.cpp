#include <bits/stdc++.h>
using namespace std;

int A, B, C, D, M, S, T, mx_s, mn_t = INT_MAX;
vector<int> dp;

int main() {
    cin >> A >> B >> C >> D >> M >> S >> T;
    dp.resize(T + 1);
    for (int i = 1; i <= T; i++) {
        if (M >= C) {
            M -= C;
            dp[i] = dp[i - 1] + B;
        } else {
            M += D;
            dp[i] = dp[i - 1];
        }
        // cout << "M: " << M << " dis: " << dp[i] << '\n';
    }
    for (int i = 0; i <= T; i++) {
        int rest_S = max(S - dp[i], 0);
        int req_t = rest_S / A + i;
        if (rest_S % A) req_t++;
        // cout << "req_t: " << req_t;
        mn_t = min(mn_t, req_t);
        mx_s = max(mx_s, dp[i] + (T - i) * A);
        // cout << " mx_s: " << mx_s << ", dp[i]: " << dp[i] << ", s: " << (T - i) * A << '\n';
    }
    if (mx_s >= S) {
        cout << "Yes\n";
        cout << mn_t;
    } else {
        cout << "No\n";
        cout << mx_s;
    }
    // for (int i = 0; i < dp.size(); i++) {
    //     cout << dp[i] << ' ';
    // }
}
// 2 1 3 3 3 100 10
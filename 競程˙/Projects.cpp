#include <bits/stdc++.h>
using namespace std;

int n, a, b, c;
vector<vector<int>> V;
vector<int> table;
vector<long long> dp(4e5 + 5);

int Search(int a) {
    return lower_bound(table.begin(), table.end(), a) - table.begin() + 1;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a >> b >> c;
        table.push_back(a);
        table.push_back(b);
        V.push_back({a, b, c});
    }
    sort(V.begin(), V.end());
    sort(table.begin(), table.end());
    table.erase(unique(table.begin(), table.end()), table.end());

    int p = 0;
    for (int i = 0; i < n; i++) {
        int start = Search(V[i][0]);
        int end = Search(V[i][1]);
        long long val = V[i][2];
        while (start > p) {
            p++;
            dp[p] = max(dp[p], dp[p - 1]);
        }
        dp[end] = max(dp[end], dp[start - 1] + val);
    }
    // cout << dp[table.size()];
    // for (int i = 0; i < 20; i++) {
    //     cout << dp[i] << ' ';
    // }
    cout << *max_element(dp.begin(), dp.end());
}

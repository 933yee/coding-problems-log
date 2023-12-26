#include <bits/stdc++.h>
using namespace std;

long long n;
vector<long long> v, s(1);
vector<vector<long long>> dp(5005, vector<long long>(5005));
vector<vector<bool>> seen(5005, vector<bool>(5005));

long long dfs(long long l, long long r) {
    if (seen[l][r]) return dp[l][r];
    if (l == r) return v[l];
    seen[l][r] = true;
    return dp[l][r] = s[r + 1] - s[l] - min(dfs(l + 1, r), dfs(l, r - 1));
}

int main() {
    cin >> n;
    for (long long i = 0; i < n; i++) {
        long long a;
        cin >> a;
        s.push_back(s.back() + a);
        v.push_back(a);
    }
    cout << dfs(0, n - 1);
}
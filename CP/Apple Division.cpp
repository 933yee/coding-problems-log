#include <bits/stdc++.h>
using namespace std;

int n;
long long sum, cnt, ans = LLONG_MAX;
vector<long long> v;

void dfs(int idx) {
    if (idx == n) return;
    cnt += v[idx];
    ans = min(ans, abs(sum - 2 * cnt));
    dfs(idx + 1);
    cnt -= v[idx];
    dfs(idx + 1);
}

int main() {
    cin >> n;
    v.resize(n);
    for (long long& i : v) {
        cin >> i;
        sum += i;
    }
    dfs(0);
    cout << ans;
}
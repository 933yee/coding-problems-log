#include <bits/stdc++.h>
using namespace std;

int N, M, ans;
vector<int> v;

int main() {
    cin >> N >> M;
    v.resize(N);
    for (int& i : v) cin >> i;
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++) {
        auto p = lower_bound(v.begin(), v.end(), v[i] + M);
        // q--;
        int t = (p - v.begin());
        ans = max(ans, t - i);
        // cout << p - v.begin() - i << '\n';
    }
    cout << ans;
}
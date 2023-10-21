#include <bits/stdc++.h>
using namespace std;

int N, M;
long long x, ans = 0;
vector<long long> v;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    v.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i];
        ans += v[i] * v[i];
    }
    sort(v.begin(), v.end());
    int t = N - M;
    for (int i = 0; i < t; i++) {
        ans += v[i] * v[2 * t - i - 1] * 2;
    }
    cout << ans << '\n';
}
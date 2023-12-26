#include <bits/stdc++.h>
using namespace std;

long long M = 1e9 + 7;
long long n, a, b, mx = 1e6 + 5;
vector<long long> v(mx);

pair<long long, long long> extgcd(long long a, long long b) {
    if (b == 0) return {1, 0};
    auto p = extgcd(b, a % b);
    return {p.second, p.first - a / b * p.second};
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    v[0] = 1;

    for (int i = 1; i <= mx; i++)
        v[i] = (v[i - 1] * i) % M;

    cin >> n;
    while (n--) {
        cin >> a >> b;
        long long ans;
        ans = (v[a] * (((extgcd(v[b], M).first) + M) % M)) % M;
        ans = (ans * (((extgcd(v[a - b], M).first) + M) % M)) % M;
        cout << ans << '\n';
    }
}
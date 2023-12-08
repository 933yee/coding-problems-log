#include <bits/stdc++.h>
using namespace std;

const long long M = 1e9 + 7;
long long a, b, c, t;

long long squared(long long k, long long d, long long mod) {
    if (d == 0) return 1;
    long long rec = squared(k, d / 2, mod) % mod;
    if (d & 1 == 1)
        return ((rec * rec) % mod * k) % mod;
    else
        return (rec * rec) % mod;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> a >> b >> c;
        b = squared(b, c, M - 1);
        a = squared(a, b, M);
        cout << a << '\n';
    }
}
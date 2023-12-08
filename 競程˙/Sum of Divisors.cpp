#include <bits/stdc++.h>
using namespace std;

long long n, ans, M = 1e9 + 7;

pair<long long, long long> extgcd(long long a, long long b) {
    if (b == 0) return {1, 0};
    auto p = extgcd(b, a % b);
    return {p.second, p.first - a / b * p.second};
}

int main() {
    cin >> n;
    for (long long i = 1, j; i <= n; i = j) {
        long long q = n / i;
        j = n / q + 1;
        long long two = extgcd(2, M).first;
        // two = (two + M) % M;
        long long R = ((((j % M) * ((j - 1) % M))) % M * two) % M;
        long long L = ((((i % M) * ((i - 1) % M))) % M * two) % M;
        long long range = (R - L + M) % M;
        ans = (ans + range * (q % M)) % M;
    }
    cout << ans;
}
#include <bits/stdc++.h>
using namespace std;

long long t, a, m1, b, m2, c, m3;

pair<long long, long long> extgcd(long long a, long long b) {
    if (b == 0) return {1, 0};
    auto p = extgcd(b, a % b);
    return {p.second, p.first - a / b * p.second};
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> m1 >> a >> m2 >> b >> m3 >> c;

        long long tmp = m2 * m3, sum = 0;
        sum += a * tmp * ((extgcd(tmp, m1).first + m1) % m1);

        tmp = m1 * m3;
        sum += b * tmp * ((extgcd(tmp, m2).first + m2) % m2);

        tmp = m1 * m2;
        sum += c * tmp * ((extgcd(tmp, m3).first + m3) % m3);

        tmp = m1 * m2 * m3;
        sum %= tmp;
        cout << sum << '\n';
    }
}
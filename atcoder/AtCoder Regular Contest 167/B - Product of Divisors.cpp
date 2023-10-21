#include <bits/stdc++.h>
using namespace std;
long long A, B, mn = LONG_LONG_MAX;
int main() {
    while (cin >> A >> B) {
        long long count = 0;
        for (long long i = 2; i <= A; i++) {
            long long tmp = 0;
            if (A % i == 0) {
                count++;
                cout << i << "QQ\n";
            }
            while (A % i == 0) {
                tmp++;
                A = A / i;
            }
            if (tmp && tmp < mn) {
                mn = tmp;
            }
        }
        cout << mn << '\n';
        long long k = (mn * (mn + 1) / 2) % 998244353;
        while (--count) {
            k *= (B + 1) % 998244353;
            k %= 998244353;
        }
        cout << k << '\n';
    }
}
#include <bits/stdc++.h>
using namespace std;

long long n;
long long mx = 1e6 + 5;
vector<long long> v;
vector<long long> A, B;
vector<vector<long long>> primes;

int main() {
    cin >> n;
    v.resize(n);
    for (long long& i : v) cin >> i;
    primes.resize(mx);
    A.resize(mx);
    B.resize(mx);

    for (long long i = 2; i < mx; i++) {
        if (primes[i].size() == 0) {
            primes[i].push_back(i);
            for (long long j = i * 2; j < mx; j += i) {
                primes[j].push_back(i);
            }
        }
    }
    for (long long i = 0; i < n; i++) {
        for (long long mask = 1; mask < (1 << primes[v[i]].size()); mask++) {
            long long c = 1, p = 0;
            for (long long j = 0; j < primes[v[i]].size(); j++) {
                if (mask & (1 << j)) {
                    c *= primes[v[i]][j];
                    p++;
                }
            }
            A[c]++;
            B[c] = p;
        }
    }
    // cout << "A: ";
    // for (long long i = 0; i < 20; i++) {
    //     cout << A[i] << ' ';
    // }
    // cout << '\n';
    // cout << "B: ";
    // for (long long i = 0; i < 20; i++) {
    //     cout << B[i] << ' ';
    // }
    long long ans = n * (n - 1) / 2;
    for (long long i = 2; i < mx; i++) {
        if (B[i] & 1 == 1)
            ans -= A[i] * (A[i] - 1) / 2;
        else
            ans += A[i] * (A[i] - 1) / 2;
    }
    cout << ans;
}
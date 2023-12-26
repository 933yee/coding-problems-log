#include <bits/stdc++.h>
using namespace std;

long long n, m, k, a, b;
long long M = 1e9 + 7;
vector<vector<long long>> G(105, vector<long long>(105));

vector<vector<long long>> calc(long long k) {
    if (k == 1) return G;
    vector<vector<long long>> ret = calc(k / 2);
    vector<vector<long long>> res(105, vector<long long>(105));

    for (long long i = 1; i <= n; i++) {
        for (long long j = 1; j <= n; j++) {
            for (long long k = 1; k <= n; k++) {
                res[i][j] += (ret[i][k] * ret[k][j]);
                res[i][j] %= M;
            }
        }
    }

    if (k & 1) {
        vector<vector<long long>> res2(105, vector<long long>(105));
        for (long long i = 1; i <= n; i++) {
            for (long long j = 1; j <= n; j++) {
                for (long long k = 1; k <= n; k++) {
                    res2[i][j] += res[i][k] * G[k][j];
                    res2[i][j] %= M;
                }
            }
        }
        return res2;
    } else
        return res;
}

int main() {
    cin >> n >> m >> k;
    for (long long i = 0; i < m; i++) {
        cin >> a >> b;
        G[a][b]++;
    }
    cout << calc(k)[1][n] % M;
}
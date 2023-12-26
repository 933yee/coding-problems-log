#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll k, n, m, x1 = 1, x2 = 1, y1 = 1, y2 = 1, dir1 = 0, dir2 = 0, purple = 0;
    cin >> k >> n >> m;
    vector<pair<ll, ll>> p(n + m + 2);
    p[0] = {1, 1};
    for (int i = 1; i <= n + m; i++)
        cin >> p[i].first;
    for (int i = n + 1; i <= n + m; i++)
        p[i].second = 1;
    p[n + m + 1] = {k + 1, 0};
    sort(p.begin(), p.end());
    for (int i = 0; i <= n + m; i++) {
        if (p[i].second)
            dir2 ^= 1;
        else
            dir1 ^= 1;
        ll seg = p[i + 1].first - p[i].first;
        if (dir1 != dir2 && x1 != x2) {
            if (x1 < x2 && x1 + seg >= x2 && dir1 == 0)
                purple++;
            else if (x2 < x1 && x2 + seg >= x1 && dir1 == 1)
                purple++;
        } else if (dir1 == dir2 && x1 == x2) {
            purple += seg;
        }
        if (dir1 == 0)
            x1 += seg;
        else
            y1 += seg;
        if (dir2 == 0)
            x2 += seg;
        else
            y2 += seg;
    }
    cout << k - purple << ' ' << k - purple << ' ' << purple << '\n';

    return 0;
}
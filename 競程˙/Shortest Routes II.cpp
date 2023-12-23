#include <bits/stdc++.h>
using namespace std;

int n, m, q, a, b;
long long c;
vector<vector<long long>> dis(505, vector<long long>(505, LONG_LONG_MAX / 2));

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> q;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        dis[a][b] = dis[b][a] = min(c, dis[a][b]);
    }
    for (int i = 1; i <= n; i++) dis[i][i] = 0;

    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                dis[i][j] = dis[j][i] = min(dis[i][j], dis[i][k] + dis[k][j]);

    for (int i = 1; i <= q; i++) {
        cin >> a >> b;
        if (dis[a][b] == LONG_LONG_MAX / 2)
            cout << "-1\n";
        else
            cout << dis[a][b] << '\n';
    }
}
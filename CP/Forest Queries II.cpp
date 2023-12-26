#include <bits/stdc++.h>
using namespace std;

int BIT[1005][1005];
char grid[1005][1005];
int n, q;

int lowbit(int x) {
    return x & (-x);
}

void modify(int x, int y, int val) {
    while (x <= n) {
        int t = y;
        while (t <= n) {
            BIT[x][t] += val;
            t += lowbit(t);
        }
        x += lowbit(x);
    }
}

int query(int x, int y) {
    int ret = 0;
    while (x >= 1) {
        int t = y;
        while (t >= 1) {
            ret += BIT[x][t];
            t -= lowbit(t);
        }
        x -= lowbit(x);
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == '*')
                modify(i, j, 1);
        }
    }
    while (q--) {
        int a, b, c, d, e;
        cin >> a;
        if (a == 1) {
            cin >> b >> c;
            if (grid[b][c] == '.') {
                grid[b][c] = '*';
                modify(b, c, 1);
            } else {
                grid[b][c] = '.';
                modify(b, c, -1);
            }
        } else {
            cin >> b >> c >> d >> e;
            cout << query(d, e) - query(b - 1, e) - query(d, c - 1) + query(b - 1, c - 1) << '\n';
        }
    }
}
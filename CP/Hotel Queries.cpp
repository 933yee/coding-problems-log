#include <bits/stdc++.h>
using namespace std;

int n, m, mx = 2e5 + 5;
vector<int> seg(4 * mx);
vector<int> v(1);

void build(int l, int r, int id) {
    if (l == r) {
        seg[id] = v[l];
        return;
    }
    int m = (l + r) / 2;
    build(l, m, id * 2);
    build(m + 1, r, id * 2 + 1);
    seg[id] = max(seg[id * 2], seg[id * 2 + 1]);
}

int query(int l, int r, int id, int s) {
    if (seg[id] < s)
        return 0;
    if (l == r) {
        seg[id] -= s;
        return l;
    }
    int m = (l + r) / 2;
    if (seg[id * 2] >= s) {
        int ret = query(l, m, id * 2, s);
        seg[id] = max(seg[id * 2], seg[id * 2 + 1]);
        return ret;
    } else {
        int ret = query(m + 1, r, id * 2 + 1, s);
        seg[id] = max(seg[id * 2], seg[id * 2 + 1]);
        return ret;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        v.push_back(x);
    }
    build(1, n, 1);
    while (m--) {
        int x;
        cin >> x;
        cout << query(1, n, 1, x) << ' ';
    }
}
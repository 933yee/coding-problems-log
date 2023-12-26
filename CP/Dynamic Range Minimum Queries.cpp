#include <bits/stdc++.h>
using namespace std;

int mx = 2e5 + 5;
vector<int> seg(mx * 4);
vector<int> v(1);
int n, q;

void build(int l, int r, int id) {
    if (l == r) {
        seg[id] = v[l];
        return;
    }
    int m = (l + r) / 2;
    build(l, m, id * 2);
    build(m + 1, r, id * 2 + 1);
    seg[id] = min(seg[id * 2], seg[id * 2 + 1]);
}

void update(int l, int r, int id, int p, int val) {
    if (p < l || p > r) return;
    if (l == r) {
        seg[id] = val;
        return;
    }
    int m = (l + r) / 2;
    update(l, m, id * 2, p, val);
    update(m + 1, r, id * 2 + 1, p, val);
    seg[id] = min(seg[id * 2], seg[id * 2 + 1]);
}

int query(int l, int r, int id, int ql, int qr) {
    if (qr < l || ql > r)
        return INT_MAX;
    else if (qr >= r && ql <= l)
        return seg[id];
    else {
        int m = (l + r) / 2;
        return min(query(l, m, id * 2, ql, qr), query(m + 1, r, id * 2 + 1, ql, qr));
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> q;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        v.push_back(x);
    }
    build(1, n, 1);
    while (q--) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == 1) {
            update(1, n, 1, b, c);
        } else {
            cout << query(1, n, 1, b, c) << '\n';
        }
    }
}
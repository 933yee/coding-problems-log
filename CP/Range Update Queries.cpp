#include <bits/stdc++.h>
using namespace std;

int mx = 2e5 + 5;
vector<long long> seg(mx * 4);
vector<long long> tag(mx * 4);
vector<long long> v(1);

void build(int l, int r, int id) {
    if (l == r) {
        seg[id] = v[l];
        return;
    }
    int m = (l + r) / 2;
    build(l, m, id * 2);
    build(m + 1, r, id * 2 + 1);
    seg[id] = seg[id * 2] + seg[id * 2 + 1];
}

void push(int l, int r, int id) {
    seg[id] += tag[id] * (r - l + 1);
    if (l != r) {
        tag[id * 2] += tag[id];
        tag[id * 2 + 1] += tag[id];
    }
    tag[id] = 0;
}

void update(int l, int r, int id, int ql, int qr, long long val) {
    if (ql <= l && qr >= r) {
        tag[id] += val;
        push(l, r, id);
        return;
    } else if (ql > r || qr < l)
        return;
    else {
        int m = (l + r) / 2;
        update(l, m, id * 2, ql, qr, val);
        update(m + 1, r, id * 2 + 1, ql, qr, val);
        seg[id] = seg[id * 2] + seg[id * 2 + 1];
    }
}

long long query(int l, int r, int id, int p) {
    int m = (l + r) / 2;
    push(l, r, id);
    if (l == r) return seg[id];
    if (m >= p)
        return query(l, m, id * 2, p);
    else
        return query(m + 1, r, id * 2 + 1, p);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        v.push_back(x);
    }
    build(1, n, 1);
    for (int i = 0; i < q; i++) {
        int a, b, c, d;
        cin >> a;
        if (a == 1) {
            cin >> b >> c >> d;
            update(1, n, 1, b, c, d);
        } else {
            cin >> b;
            cout << query(1, n, 1, b) << '\n';
        }
    }
}
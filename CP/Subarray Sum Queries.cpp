#include <bits/stdc++.h>
using namespace std;

struct Item {
    long long sum, MCS;
    long long prefix_max, postfix_max;
    Item(long long sum = 0)
        : sum(sum), MCS(max(sum, 0LL)), prefix_max(MCS), postfix_max(MCS) {}
    friend Item operator+(const Item &L, const Item &R) {
        Item res(L.sum + R.sum);
        res.MCS = max({L.MCS, R.MCS, L.postfix_max + R.prefix_max});
        res.prefix_max = max(L.prefix_max, L.sum + R.prefix_max);
        res.postfix_max = max(R.postfix_max, R.sum + L.postfix_max);
        return res;
    }
};

long long mx = 2e5 + 5;
vector<Item> seg(mx * 4);
vector<long long> v(1);
long long n, m;

void build(long long l, long long r, long long id) {
    if (l == r) {
        seg[id] = Item(v[l]);
        return;
    }
    long long m = (l + r) / 2;
    build(l, m, id * 2);
    build(m + 1, r, id * 2 + 1);
    seg[id] = seg[id * 2] + seg[id * 2 + 1];
}

void update(long long l, long long r, long long id, long long pos, long long val) {
    if (l == r) {
        seg[id] = Item(val);
        return;
    }
    long long m = (l + r) / 2;
    if (m >= pos)
        update(l, m, id * 2, pos, val);
    else
        update(m + 1, r, id * 2 + 1, pos, val);
    seg[id] = seg[id * 2] + seg[id * 2 + 1];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (long long i = 0; i < n; i++) {
        long long x;
        cin >> x;
        v.push_back(x);
    }
    build(1, n, 1);
    while (m--) {
        long long a, b;
        cin >> a >> b;
        update(1, n, 1, a, b);
        cout << seg[1].MCS << '\n';
    }
}
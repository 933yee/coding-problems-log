#include <bits/stdc++.h>
using namespace std;

struct node {
    node() {}
    node(long long a, long long b) {
        dis = a;
        id = b;
    }
    long long dis = 0, id;
    bool operator<(const node& a) const {
        return dis > a.dis;
    }
};

struct edge {
    edge() {}
    edge(long long b, long long c) {
        to = b;
        weight = c;
    }
    long long to, weight;
};

long long n, m, a, b, c, mx = 1e5 + 5;
vector<vector<edge>> G(mx);
priority_queue<node> pq;
vector<bool> seen(mx);
vector<long long> ans(mx);

void bfs() {
    pq.push(node(0, 1));
    long long cnt = 0;
    while (!pq.empty()) {
        node cur = pq.top();
        pq.pop();
        if (seen[cur.id]) continue;
        seen[cur.id] = true;
        ans[cur.id] = cur.dis;
        cnt++;
        // cout << cur.id << ' ' << cur.dis << '\n';
        if (cnt == n) return;
        for (edge& i : G[cur.id]) {
            if (!seen[i.to])
                pq.push(node(i.weight + cur.dis, i.to));
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        G[a].push_back(edge(b, c));
    }

    bfs();

    for (int i = 1; i <= n; i++) {
        cout << ans[i] << ' ';
    }
}
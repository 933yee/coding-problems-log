#include <bits/stdc++.h>
using namespace std;

struct edge {
    edge() {}
    edge(int t, int w) {
        weight = w;
        to = t;
    }
    bool operator<(const edge& b) const {
        return weight > b.weight;
    }

    long long weight;
    int to;
};

int n, m, a, b, mx = 1e5 + 5;
long long c, ans;
vector<vector<edge>> edges(mx);
priority_queue<edge> pq;
vector<long long> weight(mx, LONG_LONG_MAX);
vector<bool> visited(mx);

void Prim() {
    weight[1] = 0;
    pq.push(edge(1, 0));
    long long ans = 0;
    int cnt = 0;
    while (!pq.empty()) {
        edge cur = pq.top();
        pq.pop();
        if (visited[cur.to]) continue;
        visited[cur.to] = true;
        ans += cur.weight;
        cnt++;
        for (edge e : edges[cur.to]) {
            if (!visited[e.to])
                pq.push(e);
        }
    }
    if (cnt == n)
        cout << ans;
    else
        cout << "IMPOSSIBLE";
}

int main() {
    cin >> n >> m;
    while (m--) {
        cin >> a >> b >> c;
        edges[a].push_back(edge(b, c));
        edges[b].push_back(edge(a, c));
    }
    Prim();
}
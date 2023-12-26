#include <bits/stdc++.h>
using namespace std;

struct edge {
    edge() {}
    edge(int f, int t, int w) {
        weight = w;
        to = t;
        from = f;
    }
    bool operator<(edge& b) const {
        return weight < b.weight;
    }

    long long weight;
    int from, to;
};

int n, m, a, b, mx = 1e5 + 5;
long long c, ans;
vector<edge> edges;
vector<int> parent(mx);

void init() {
    for (int i = 1; i <= n; i++)
        parent[i] = i;
}

int find_root(int a) {
    if (a == parent[a]) return a;
    return parent[a] = find_root(parent[a]);
}

bool Same(int a, int b) {
    return find_root(a) == find_root(b);
}

void Union(int a, int b) {
    parent[find_root(a)] = find_root(b);
}

void Kruskal() {
    init();
    int cnt = 0;
    sort(edges.begin(), edges.end());
    for (edge& e : edges) {
        if (!Same(e.from, e.to)) {
            Union(e.from, e.to);
            cnt++;
            ans += e.weight;
        }
    }
    if (cnt == n - 1)
        cout << ans;
    else
        cout << "IMPOSSIBLE";
}

int main() {
    cin >> n >> m;
    while (m--) {
        cin >> a >> b >> c;
        edges.push_back(edge(a, b, c));
    }
    Kruskal();
}
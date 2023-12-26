#include <bits/stdc++.h>
using namespace std;

int N, Q, mx = 2e5 + 5;
vector<int> parent(mx);

void init() {
    for (int i = 0; i <= N; i++) {
        parent[i] = i;
    }
}

int find_root(int a) {
    if (parent[a] == a) return a;
    return parent[a] = find_root(parent[a]);
}

void Union(int a, int b) {
    parent[find_root(a)] = find_root(b);
}

bool Same(int a, int b) {
    return parent[find_root(a)] == parent[find_root(b)];
}

int main() {
    cin >> N >> Q;
    init();
    for (int i = 0; i < Q; i++) {
        int l, r;
        cin >> l >> r;
        Union(l - 1, r);
    }
    cout << (Same(0, N) ? "Yes" : "No");
}
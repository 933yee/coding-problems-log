#include <bits/stdc++.h>
using namespace std;

int N, K, L, mx = 2e5 + 5, a, b;
vector<int> parent(mx), parent2(mx);

void init() {
    for (int i = 1; i <= N; i++) {
        parent[i] = i;
        parent2[i] = i;
    }
}

int find_root(vector<int>& parent, int a) {
    if (a == parent[a]) return a;
    return parent[a] = find_root(parent, parent[a]);
}

int Same(vector<int>& parent, int a, int b) {
    return parent[find_root(parent, a)] == parent[find_root(parent, b)];
}

void Union(int a, int b, vector<int>& parent, bool add_sz) {
    int c = find_root(parent, a), d = find_root(parent, b);
    if (c == d) return;
    parent[c] = d;
}

int main() {
    cin >> N >> K >> L;
    parent.resize(N + 1);
    parent2.resize(N + 1);
    init();
    for (int i = 0; i < K; i++) {
        cin >> a >> b;
        Union(a, b, parent, false);
    }
    for (int i = 0; i < L; i++) {
        cin >> a >> b;
        Union(a, b, parent2, true);
    }
    map<pair<int, int>, int> mp;
    for (int i = 1; i <= N; i++) {
        mp[{find_root(parent, i), find_root(parent2, i)}]++;
    }

    for (int i = 1; i <= N; i++) {
        cout << mp[{find_root(parent, i), find_root(parent2, i)}] << ' ';
    }
}
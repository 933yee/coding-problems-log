#include <bits/stdc++.h>
using namespace std;
void dfs_r(int);
void dfs(int);

void dfs_r(int n) {
    if (n <= 0) return;
    dfs_r(n - 1);
    dfs(n - 2);
    cout << "Move ring " << n << " in" << '\n';
    dfs_r(n - 2);
}

void dfs(int n) {
    if (n <= 0) return;
    dfs(n - 2);
    cout << "Move ring " << n << " out" << '\n';
    dfs_r(n - 2);
    dfs(n - 1);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    dfs(n);
}

// Move ring 1 out
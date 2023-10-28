#include <bits/stdc++.h>
using namespace std;

int r, c;
vector<string> s;
int cnt = 0;
void dfs(int x, int y) {
    if (x < 0 || y >= c || x >= r || y < 0 || s[x][y] == '.') return;
    s[x][y] = '.';
    dfs(x - 1, y);
    dfs(x - 1, y + 1);
    dfs(x, y + 1);
    dfs(x + 1, y + 1);
    dfs(x + 1, y);
    dfs(x + 1, y - 1);
    dfs(x, y - 1);
    dfs(x - 1, y - 1);
}

int main() {
    cin >> r >> c;
    for (int i = 0; i < r; i++) {
        string k;
        cin >> k;
        s.push_back(k);
    }
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (s[i][j] == '#') {
                cnt++;
                dfs(i, j);
            }
        }
    }
    cout << cnt << '\n';
}
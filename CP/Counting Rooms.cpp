#include <bits/stdc++.h>
using namespace std;

int n, m, ans;
vector<string> mp;
vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

void bfs(int x, int y) {
    queue<pair<int, int>> q;
    q.emplace(x, y);
    mp[x][y] = '#';
    while (!q.empty()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();
        for (auto& dir : dirs) {
            if (x + dir.first >= 0 && x + dir.first < n && y + dir.second >= 0 && y + dir.second < m && mp[x + dir.first][y + dir.second] == '.') {
                mp[x + dir.first][y + dir.second] = '#';
                q.emplace(x + dir.first, y + dir.second);
            }
        }
    }
}

int main() {
    cin >> n >> m;
    mp.resize(n);

    for (string& s : mp) cin >> s;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (mp[i][j] == '.') {
                bfs(i, j);
                ans++;
            }
    cout << ans;
}
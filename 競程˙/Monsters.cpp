#include <bits/stdc++.h>
using namespace std;

int n, m, step;
char mp[1005][1005];
int mpdir[1005][1005];
vector<pair<int, int>> monsters, dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
string lastDir = "DURL", path;
pair<int, int> player, door;
queue<pair<int, int>> q;
bool found = false;
int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> mp[i][j];
            if (mp[i][j] == 'M') {
                q.push({i, j});
            }
            if (mp[i][j] == 'A') {
                player = {i, j};
            }
        }
    }
    q.push(player);
    while (!q.empty()) {
        for (int i = q.size(); i--;) {
            auto cur = q.front();
            q.pop();
            for (int j = 0; j < 4; j++) {
                int nextx = cur.first + dir[j].first;
                int nexty = cur.second + dir[j].second;
                if (nextx < 0 || nextx >= n || nexty < 0 || nexty >= m) {
                    if (mp[cur.first][cur.second] == 'A') {
                        found = true;
                        door = cur;
                        break;
                    }
                } else if (mp[nextx][nexty] == '.') {
                    q.push({nextx, nexty});
                    mp[nextx][nexty] = mp[cur.first][cur.second];
                    mpdir[nextx][nexty] = j;
                }
            }
        }
        if (found) break;
        step++;
    }
    if (found) {
        while (door != player) {
            int d = mpdir[door.first][door.second];
            path += lastDir[d];
            door.first -= dir[d].first;
            door.second -= dir[d].second;
        }
        reverse(path.begin(), path.end());
        cout << "YES\n";
        cout << step << '\n';
        cout << path;
    } else {
        cout << "NO\n";
    }
}
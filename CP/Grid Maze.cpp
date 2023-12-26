#include <bits/stdc++.h>
using namespace std;

int n, m, step;
char mp[1005][1005];
pair<int, int> A, B;
vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
string tar = "DURL";
char dirTable[1005][1005];
queue<pair<int, int>> q;
int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> mp[i][j];
            if (mp[i][j] == 'A') {
                A = {i, j};
                q.push({i, j});
                mp[i][j] = '#';
            }
            if (mp[i][j] == 'B') {
                B = {i, j};
            }
        }
    }

    while (!q.empty()) {
        for (int i = q.size(); i--;) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            if (x == B.first && y == B.second) {
                cout << "YES\n";
                cout << step << '\n';
                string ans;
                // ans += dirTable[B.first][B.second];
                while (A != B) {
                    ans += dirTable[B.first][B.second];
                    if (dirTable[B.first][B.second] == 'U') {
                        B.first += dirs[0].first;
                        B.second += dirs[0].second;
                    } else if (dirTable[B.first][B.second] == 'D') {
                        B.first += dirs[1].first;
                        B.second += dirs[1].second;
                    } else if (dirTable[B.first][B.second] == 'L') {
                        B.first += dirs[2].first;
                        B.second += dirs[2].second;
                    } else if (dirTable[B.first][B.second] == 'R') {
                        B.first += dirs[3].first;
                        B.second += dirs[3].second;
                    }
                }
                reverse(ans.begin(), ans.end());
                cout << ans << '\n';
                return 0;
            }
            for (int i = 0; i < 4; i++) {
                int nxtx = x + dirs[i].first;
                int nxty = y + dirs[i].second;
                if (nxtx >= 0 && nxtx < n && nxty >= 0 && nxty < m && mp[nxtx][nxty] != '#') {
                    q.push({nxtx, nxty});
                    mp[nxtx][nxty] = '#';
                    dirTable[nxtx][nxty] = tar[i];
                }
            }
        }
        step++;
    }
    cout << "NO";
}
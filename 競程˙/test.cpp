#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n, m, a[1005][1005], d[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}}, dir[1005][1005];
pair<int, int> A, B;
vector<char> v;
string s, tar = " DURL";

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> s;
        for (int j = 0; j < m; j++) {
            if (s[j] == '#')
                a[i][j] = 0;
            else
                a[i][j] = 1;
            if (s[j] == 'A')
                A = {i, j};
            else if (s[j] == 'B')
                B = {i, j};
        }
    }
    queue<pair<int, int> > q;
    q.push(A);
    while (!q.empty()) {
        auto now = q.front();
        q.pop();
        for (int k = 0; k < 4; k++) {
            int x = now.first + d[k][0];
            int y = now.second + d[k][1];
            if (0 <= x && x < n && 0 <= y && y < m && a[x][y]) {
                a[x][y] = 0;
                dir[x][y] = k + 1;
                q.push({x, y});
            }
        }
    }
    if (!dir[B.first][B.second]) {
        cout << "NO\n";
        return 0;
    }
    while (B != A) {
        v.push_back(tar[dir[B.first][B.second]]);
        pair<int, int> nxt = {B.first - d[dir[B.first][B.second] - 1][0], B.second - d[dir[B.first][B.second] - 1][1]};
        B = nxt;
    }
    reverse(v.begin(), v.end());
    cout << "YES\n";
    cout << v.size() << "\n";
    for (auto i : v) {
        cout << i;
    }
}
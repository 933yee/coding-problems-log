#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define IOS                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
#define lowbit(x) ((x) & -(x))
const ll M = 1e9 + 7;

int mp[7][7];
int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
ll ans;
string op;

void dfs(int x, int y, int step, int lastx, int lasty) {
    if (step == 48 && x == 6 && y == 0) {
        ans++;
        // for (int i = 0; i < 7; i++) {
        //     for (int j = 0; j < 7; j++) {
        //         cout << mp[i][j] << ' ';
        //     }
        //     cout << '\n';
        // }
        return;
    }
    if (step == 48 || (x == 6 && y == 0)) return;
    // for (int i = 0; i < 7; i++) {
    //     for (int j = 0; j < 7; j++) {
    //         cout << mp[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    // cout << '\n';
    int x1 = x - 1, x2 = x + 1, x3 = x, x4 = x;
    int y1 = y, y2 = y, y3 = y - 1, y4 = y + 1;
    if (x - 1 >= 0 && y - 1 >= 0 && mp[x - 1][y - 1] && !mp[x - 1][y] && !mp[x][y - 1]) return;
    if (x + 1 < 7 && y - 1 >= 0 && mp[x + 1][y - 1] && !mp[x + 1][y] && !mp[x][y - 1]) return;
    if (x + 1 < 7 && y + 1 < 7 && mp[x + 1][y + 1] && !mp[x + 1][y] && !mp[x][y + 1]) return;
    if (x - 1 >= 0 && y + 1 < 7 && mp[x - 1][y + 1] && !mp[x - 1][y] && !mp[x][y + 1]) return;

    if ((x1 != lastx || y1 != lasty) && (x1 < 0 || mp[x1][y1] == 1) && (y3 >= 0 && y4 < 7 && mp[x3][y3] == 0 && mp[x4][y4] == 0)) return;
    if ((x2 != lastx || y2 != lasty) && (x2 >= 7 || mp[x2][y2] == 1) && (y3 >= 0 && y4 < 7 && mp[x3][y3] == 0 && mp[x4][y4] == 0)) return;
    if ((x3 != lastx || y3 != lasty) && (y3 < 0 || mp[x3][y3] == 1) && (x1 >= 0 && x2 < 7 && mp[x1][y1] == 0 && mp[x2][y2] == 0)) return;
    if ((x4 != lastx || y4 != lasty) && (y4 >= 7 || mp[x4][y4] == 1) && (x1 >= 0 && x2 < 7 && mp[x1][y1] == 0 && mp[x2][y2] == 0)) return;

    if (op[step] == 'U' || op[step] == '?') {
        if (x1 >= 0 && mp[x1][y1] == 0) {
            mp[x1][y1] = 1;
            dfs(x1, y1, step + 1, x, y);
            mp[x1][y1] = 0;
        }
    }
    if (op[step] == 'D' || op[step] == '?') {
        if (x2 < 7 && mp[x2][y2] == 0) {
            mp[x2][y2] = 1;
            dfs(x2, y2, step + 1, x, y);
            mp[x2][y2] = 0;
        }
    }
    if (op[step] == 'L' || op[step] == '?') {
        if (y3 >= 0 && mp[x3][y3] == 0) {
            mp[x3][y3] = 1;
            dfs(x3, y3, step + 1, x, y);
            mp[x3][y3] = 0;
        }
    }

    if (op[step] == 'R' || op[step] == '?') {
        if (y4 < 7 && mp[x4][y4] == 0) {
            mp[x4][y4] = 1;
            dfs(x4, y4, step + 1, x, y);
            mp[x4][y4] = 0;
        }
    }
}

int main() {
    IOS;
    cin >> op;
    mp[0][0] = 1;
    dfs(0, 0, 0, -1, -1);
    cout << ans;
}
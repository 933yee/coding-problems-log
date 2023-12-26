#include <bits/stdc++.h>
using namespace std;

string s;
bool seen[7][7];
long long ans = 0;

bool valid(int x, int y) {
    return x >= 0 && y >= 0 && x < 7 && y < 7 && !seen[x][y];
}

void dfs(int x, int y, int op_cnt, string last_dir) {
    if (op_cnt == 48) {
        if (x == 0 && y == 6)
            ans++;
        return;
    } else if (x == 0 && y == 6)
        return;
    if (x - 1 >= 0 && y - 1 >= 0 && seen[x - 1][y - 1] && !seen[x - 1][y] && !seen[x][y - 1]) return;
    if (x + 1 < 7 && y - 1 >= 0 && seen[x + 1][y - 1] && !seen[x + 1][y] && !seen[x][y - 1]) return;
    if (x + 1 < 7 && y + 1 < 7 && seen[x + 1][y + 1] && !seen[x + 1][y] && !seen[x][y + 1]) return;
    if (x - 1 >= 0 && y + 1 < 7 && seen[x - 1][y + 1] && !seen[x - 1][y] && !seen[x][y + 1]) return;

    if (last_dir != "L" && !valid(x + 1, y) && valid(x, y - 1) && valid(x, y + 1)) return;
    if (last_dir != "R" && !valid(x - 1, y) && valid(x, y - 1) && valid(x, y + 1)) return;
    if (last_dir != "U" && !valid(x, y + 1) && valid(x + 1, y) && valid(x - 1, y)) return;
    if (last_dir != "D" && !valid(x, y - 1) && valid(x + 1, y) && valid(x - 1, y)) return;

    if (s[op_cnt] == 'U' || s[op_cnt] == '?') {
        if (valid(x, y - 1)) {
            seen[x][y - 1] = true;
            dfs(x, y - 1, op_cnt + 1, "U");
            seen[x][y - 1] = false;
        }
    }
    if (s[op_cnt] == 'D' || s[op_cnt] == '?') {
        if (valid(x, y + 1)) {
            seen[x][y + 1] = true;
            dfs(x, y + 1, op_cnt + 1, "D");
            seen[x][y + 1] = false;
        }
    }
    if (s[op_cnt] == 'L' || s[op_cnt] == '?') {
        if (valid(x - 1, y)) {
            seen[x - 1][y] = true;
            dfs(x - 1, y, op_cnt + 1, "L");
            seen[x - 1][y] = false;
        }
    }
    if (s[op_cnt] == 'R' || s[op_cnt] == '?') {
        if (valid(x + 1, y)) {
            seen[x + 1][y] = true;
            dfs(x + 1, y, op_cnt + 1, "R");
            seen[x + 1][y] = false;
        }
    }
}

int main() {
    cin >> s;
    seen[0][0] = true;
    dfs(0, 0, 0, "");
    cout << ans;
}
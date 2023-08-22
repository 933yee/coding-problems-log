#include <bits/stdc++.h>
using namespace std;
const int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
vector<vector<int>> seen(10, vector<int>(10));
string op;
int dfs(int x, int y, int opPos, int dx, int dy) {
    if (opPos == 48 && x != 7 && y != 1) return 0;
    if (x == 7 && y == 1) return opPos == 48;
    int walkable = 0, ret = 0, X, Y;

    // if (x - 1 >= 1 && y - 1 >= 1 && seen[x - 1][y - 1] && !seen[x - 1][y] && !seen[x][y - 1]) return 0;
    // if (x + 1 <= 7 && y - 1 >= 1 && seen[x + 1][y - 1] && !seen[x + 1][y] && !seen[x][y - 1]) return 0;
    // if (x + 1 <= 7 && y + 1 <= 7 && seen[x + 1][y + 1] && !seen[x + 1][y] && !seen[x][y + 1]) return 0;
    // if (x - 1 >= 1 && y + 1 <= 7 && seen[x - 1][y + 1] && !seen[x - 1][y] && !seen[x][y + 1]) return 0;
    // for (int i = 0; i < 4; i++) {
    //     if (opPos == 0) break;
    //     X = x + dir[i][0], Y = y + dir[i][1];
    //     if (X <= 7 && X >= 1 && Y <= 7 && Y >= 1 && !seen[X][Y]) walkable++;
    // }
    // if (walkable == 2 && (x + dx < 1 || x + dx > 7 || y + dy < 1 || y + dy > 7 || seen[x + dx][y + dy])) return 0;
    if (op[opPos] == 'R') {
        if (y + 1 <= 7 && !seen[x][y + 1]) {
            seen[x][y + 1] = true;
            ret += dfs(x, y + 1, opPos + 1, 0, 1);
            seen[x][y + 1] = false;
        }
    } else if (op[opPos] == 'L') {
        if (y - 1 >= 1 && !seen[x][y - 1]) {
            seen[x][y - 1] = true;
            ret += dfs(x, y - 1, opPos + 1, 0, -1);
            seen[x][y - 1] = false;
        }
    } else if (op[opPos] == 'U') {
        if (x - 1 >= 1 && !seen[x - 1][y]) {
            seen[x - 1][y] = true;
            ret += dfs(x - 1, y, opPos + 1, -1, 0);
            seen[x - 1][y] = false;
        }
    } else if (op[opPos] == 'D') {
        if (x + 1 <= 7 && !seen[x + 1][y]) {
            seen[x + 1][y] = true;
            ret += dfs(x + 1, y, opPos + 1, 1, 0);
            seen[x + 1][y] = false;
        }
    } else {
        for (int i = 0; i < 4; i++) {
            int X = x + dir[i][0], Y = y + dir[i][1];
            if (X <= 7 && X >= 1 && Y <= 7 && Y >= 1 && !seen[X][Y]) {
                seen[X][Y] = true;
                ret += dfs(X, Y, opPos + 1, dir[i][0], dir[i][1]);
                seen[X][Y] = false;
            }
        }
    }
    return ret;
}
int main() {
    // clock_t start = clock();
    cin >> op;
    seen[1][1] = true;
    cout << dfs(1, 1, 0, 0, 0) << '\n';
    // clock_t end = clock();
    // cout << (double)(end-start)/CLOCKS_PER_SEC;
}
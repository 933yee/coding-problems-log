#include <bits/stdc++.h>
using namespace std;
int grid[5][5];
vector<int> ans, cur;
int min_sum = INT_MAX;
void dfs(int n, int pos) {
    if (n == 5) {
        int sum = 0;
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                if (grid[i][j]) {
                    int min_dis = INT_MAX;
                    for (int k = 0; k < 5; k++) {
                        int row = cur[k] / 5, col = cur[k] % 5;
                        int dis = abs(row - i) + abs(col - j);
                        if (dis < min_dis)
                            min_dis = dis;
                    }
                    sum += min_dis * grid[i][j];
                }
            }
        }
        if (sum < min_sum) {
            ans = cur;
            min_sum = sum;
        }

        return;
    }
    for (int i = pos; i < 25; i++) {
        cur.push_back(i);
        dfs(n + 1, i + 1);
        cur.pop_back();
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int row, col, val;
        memset(grid, 0, sizeof(grid));
        min_sum = INT_MAX;
        while (n--) {
            cin >> row >> col >> val;
            grid[row][col] = val;
        }
        dfs(0, 0);
        for (int i = 0; i < 5; i++)
            cout << ans[i] << ((i == 4) ? '\n' : ' ');
    }
}
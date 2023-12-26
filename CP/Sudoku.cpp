#include <bits/stdc++.h>
using namespace std;

string s;
int MASK = (1 << 9) - 1;
int row[9], col[9], sub[3][3];
unordered_map<int, int> table{
    {1, 1},
    {2, 2},
    {4, 3},
    {8, 4},
    {16, 5},
    {32, 6},
    {64, 7},
    {128, 8},
    {256, 9},
};
int lowbit(int x) {
    return x & (~x + 1);
}

void update(int r, int c, int num) {
    row[r] ^= num;
    col[c] ^= num;
    sub[r / 3][c / 3] ^= num;
}

bool dfs(int n) {
    if (n == 81) return true;
    int r = n / 9, c = n % 9;
    if (s[n] == '.') {
        int S = MASK & ~(row[r] | col[c] | sub[r / 3][c / 3]);
        for (int num = 0; S; S ^= num) {
            num = lowbit(S);
            update(r, c, num);
            s[n] = table[num] + '0';
            if (dfs(n + 1)) return true;
            s[n] = '.';
            update(r, c, num);
        }
    } else {
        if (dfs(n + 1))
            return true;
    }
    return false;
}

bool valid(int r, int c, int num) {
    if (row[r] & num) return false;
    if (col[c] & num) return false;
    if (sub[r / 3][c / 3] & num) return false;
    return true;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    while (cin >> s && s != "end") {
        memset(row, 0, sizeof(row));
        memset(col, 0, sizeof(col));
        memset(sub, 0, sizeof(sub));
        bool flag = false;
        for (int i = 0; i < 81; i++) {
            if (s[i] != '.') {
                int r = i / 9, c = i % 9;
                if (!valid(r, c, (1 << (s[i] - '0' - 1)))) {
                    flag = true;
                    break;
                }
                update(r, c, (1 << (s[i] - '0' - 1)));
            }
        }
        if (!flag && dfs(0))
            cout << s << '\n';
        else
            cout << "No solution.\n";
    }
}
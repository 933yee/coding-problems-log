#include <bits/stdc++.h>
using namespace std;

int N;
string R, C;
char ans[5][5];
string s = "ABC.";

bool isValid(int r, int c, char ch) {
    if (r == N - 1) {
        int cntA, cntB, cntC;
        cntA = cntB = cntC = 0;
        for (int i = 0; i < N; i++) {
            if (ans[i][c] == 'A') cntA++;
            if (ans[i][c] == 'B') cntB++;
            if (ans[i][c] == 'C') cntC++;
        }
        if (cntA != 1 || cntB != 1 || cntC != 1) return false;
    }
    if (ch == '.') return true;
    int cntA, cntB, cntC;
    cntA = cntB = cntC = 0;
    for (int i = 0; i <= c; i++) {
        if (ans[r][i] == 'A') cntA++;
        if (ans[r][i] == 'B') cntB++;
        if (ans[r][i] == 'C') cntC++;
    }
    if (cntA > 1 || cntB > 1 || cntC > 1) return false;
    cntA = cntB = cntC = 0;
    for (int i = 0; i <= r; i++) {
        if (ans[i][c] == 'A') cntA++;
        if (ans[i][c] == 'B') cntB++;
        if (ans[i][c] == 'C') cntC++;
    }
    if (cntA > 1 || cntB > 1 || cntC > 1) return false;
    for (int i = 0; i <= r; i++) {
        if (ans[i][c] != '.') {
            if (ans[i][c] == C[c]) break;
            return false;
        }
    }
    for (int i = 0; i <= c; i++) {
        if (ans[r][i] != '.') {
            if (ans[r][i] == R[r]) break;
            return false;
        }
    }
    return true;
}

bool dfs(int r, int c) {
    // cout << r << ' ' << c << '\n';
    if (r == N) return true;
    if (c == N) {
        int cntA, cntB, cntC;
        cntA = cntB = cntC = 0;
        for (int i = 0; i < N; i++) {
            if (ans[r][i] == 'A') cntA++;
            if (ans[r][i] == 'B') cntB++;
            if (ans[r][i] == 'C') cntC++;
        }
        if (cntA != 1 || cntB != 1 || cntC != 1) return false;
        return dfs(r + 1, 0);
    }
    for (char& ch : s) {
        ans[r][c] = ch;
        if (isValid(r, c, ch)) {
            if (dfs(r, c + 1))
                return true;
        }
        ans[r][c] = '.';
    }
    return false;
}

int main() {
    cin >> N >> R >> C;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            ans[i][j] = '.';
    if (dfs(0, 0)) {
        cout << "Yes\n";
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cout << ans[i][j];
            }
            cout << '\n';
        }
    } else {
        cout << "No";
    }
}
#include <bits/stdc++.h>
using namespace std;

int t;
int M, N, MASK;
long long ans;

int lowbit(int x) {
    return x & (~x + 1);
}

void dfs(int l1, int m1, int r1, int l2, int m2, int r2, int cnt, int Q_num, int R_num) {
    if (cnt == M + N) {
        ans++;
        return;
    }
    if (Q_num > 0) {
        int S = MASK & ~(l1 | m1 | r1);
        for (int num = 0; S; S ^= num) {
            num = lowbit(S);
            dfs((l1 | num) << 1, m1 | num, (r1 | num) >> 1, (l2 | num) << 1, m2 | num, (r2 | num) >> 1, cnt + 1, Q_num - 1, R_num);
        }
    }
    if (R_num > 0) {
        int S = MASK & ~(l2 | m2 | r2);
        for (int num = 0; S; S ^= num) {
            num = lowbit(S);
            dfs((l1 | num) << 1, m1 | num, (r1 | num) >> 1, l2 << 1, m2 | num, r2 >> 1, cnt + 1, Q_num, R_num - 1);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--) {
        ans = 0;
        cin >> M >> N;
        MASK = (1 << (M + N)) - 1;
        dfs(0, 0, 0, 0, 0, 0, 0, M, N);
        cout << ans << '\n';
    }
}
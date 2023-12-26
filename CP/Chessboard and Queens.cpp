#include <bits/stdc++.h>
using namespace std;

vector<string> mp(8);
int ans;
void dfs(int l, int m, int r, int cnt) {
    if (cnt == 8) {
        ans++;
        return;
    }
    for (int i = 0; i < 8; i++) {
        int cur = (1 << i);
        if (mp[cnt][i] == '.' && ((l | m | r) & cur) == 0) {
            dfs((l | cur) << 1, m | cur, (r | cur) >> 1, cnt + 1);
        }
    }
}

int main() {
    for (string& s : mp)
        cin >> s;

    dfs(0, 0, 0, 0);
    cout << ans << '\n';
}
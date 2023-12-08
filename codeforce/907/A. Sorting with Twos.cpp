#include <bits/stdc++.h>
using namespace std;
int t, n;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    // t = 1;
    while (t--) {
        cin >> n;
        vector<int> v(n + 1);
        for (int i = 1; i <= n; i++) cin >> v[i];
        int cnt = 1;
        int last_cnt = 0;
        bool valid = true;
        while (cnt <= n) {
            for (int i = last_cnt + 1; i < cnt; i++) {
                if (v[i] > v[i + 1]) {
                    valid = false;
                    // cout << i << "QQ\n";
                    // cout << cnt << "QQ\n";
                    break;
                }
            }
            if (!valid) break;
            last_cnt = cnt;
            cnt *= 2;
        }
        for (int i = last_cnt + 1; i < n; i++) {
            if (v[i] > v[i + 1]) {
                valid = false;
                break;
            }
        }
        if (valid)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}

// 9
// 1 2 3 4 5 6 7 0 1
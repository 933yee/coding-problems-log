#include <bits/stdc++.h>
using namespace std;

int t, n, q, sum;
vector<int> v;
vector<bool> seen;

bool dfs(int idx, int cur, int cnt) {
    if (cnt == 3) return true;
    if (cur == q) return dfs(0, 0, cnt + 1);
    if (cur > q) return false;
    for (int i = idx; i < n; i++) {
        if (!seen[i]) {
            seen[i] = true;
            if (dfs(i + 1, cur + v[i], cnt))
                return true;
            seen[i] = false;
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n;
        v.clear();
        seen.clear();
        v.resize(n);
        seen.resize(n);
        sum = 0;
        for (int& i : v) {
            cin >> i;
            sum += i;
        }
        if (sum % 4 == 0) {
            q = sum / 4;

            if (dfs(0, 0, 0)) {
                cout << "yes\n";
            } else {
                cout << "no\n";
            }

        } else
            cout << "no\n";
    }
}
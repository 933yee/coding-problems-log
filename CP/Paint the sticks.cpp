#include <bits/stdc++.h>
using namespace std;

int n, x;
long long ans;
stack<pair<int, int>> stk;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    while (cin >> n) {
        while (!stk.empty()) stk.pop();
        ans = 0;
        for (int i = 0; i < n; i++) {
            cin >> x;
            int corner = i;
            while (!stk.empty() && stk.top().first >= x) {
                corner = stk.top().second;
                ans = max(ans, 1LL * (i - corner) * stk.top().first);
                stk.pop();
            }
            stk.push({x, corner});
        }
        x = 0;
        int corner = n;
        while (!stk.empty() && stk.top().first >= x) {
            corner = stk.top().second;
            ans = max(ans, 1LL * (n - corner) * stk.top().first);
            stk.pop();
        }
        cout << ans << '\n';
    }
}
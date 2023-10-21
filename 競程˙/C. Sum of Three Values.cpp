#include <bits/stdc++.h>
using namespace std;

int n, x;
vector<pair<int, int>> v;

int main() {
    cin >> n >> x;
    for (int i = 1; i <= n; i++) {
        int a;
        cin >> a;
        v.push_back({a, i});
    }
    sort(v.begin(), v.end());
    // for (auto& i : v) {
    // cout << i.first << ' ' << i.second << '\n';
    // }
    for (int i = 0; i < n; i++) {
        int l = i + 1, r = n - 1;
        long long target = x - v[i].first;
        while (l < r) {
            long long tmp = v[l].first + v[r].first;
            if (tmp > target)
                r--;
            else if (tmp < target)
                l++;
            else {
                cout << v[i].second << ' ' << v[l].second << ' ' << v[r].second << '\n';
                return 0;
            }
        }
    }
    cout << "IMPOSSIBLE\n";
}
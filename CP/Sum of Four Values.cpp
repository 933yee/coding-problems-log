#include <bits/stdc++.h>
using namespace std;

int n, tar, x;
vector<long long> v;
map<long long, pair<int, int>> mp;

int main() {
    cin >> n >> tar;
    for (int i = 0; i < n; i++) {
        cin >> x;
        v.push_back(x);
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (mp.count(tar - v[i] - v[j])) {
                auto p = mp[tar - v[i] - v[j]];
                cout << i + 1 << ' ' << j + 1 << ' ' << p.first + 1 << ' ' << p.second + 1;
                return 0;
            }
        }
        for (int j = 0; j < i; j++) {
            mp[v[i] + v[j]] = {i, j};
        }
    }
    cout << "IMPOSSIBLE";
}
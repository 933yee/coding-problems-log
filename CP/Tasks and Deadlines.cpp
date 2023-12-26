#include <bits/stdc++.h>
using namespace std;

int n;
long long ans = 0, cnt = 0;
vector<pair<int, int>> v;

bool cmp(pair<int, int>& a, pair<int, int>& b) {
    return a.first < b.first;
}

int main() {
    cin >> n;
    while (n--) {
        int a, b;
        cin >> a >> b;
        v.push_back({a, b});
    }
    sort(v.begin(), v.end(), cmp);
    for (auto& i : v) {
        cnt += i.first;
        ans += i.second - cnt;
    }
    cout << ans;
}
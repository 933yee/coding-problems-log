#include <bits/stdc++.h>
using namespace std;

int t, N, x;
vector<vector<int>> v;

bool cmp(vector<int>& a, vector<int>& b) {
    long long sum1 = 0, sum2 = 0;
    int mx1 = INT_MIN, mx2 = INT_MIN;
    for (int i = 0; i < a.size() - 1; i++) {
        sum1 += a[i];
        mx1 = max(mx1, a[i]);
    }
    for (int i = 0; i < b.size() - 1; i++) {
        sum2 += b[i];
        mx2 = max(mx2, b[i]);
    }
    if (sum1 != sum2) return sum1 > sum2;
    if (mx1 != mx2) return mx1 > mx2;
    if (a.size() != b.size()) return a.size() > b.size();
    return a.back() < b.back();
    // return sum1 < sum2;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> N;
        v.clear();
        v.resize(N);
        for (int i = 0; i < N; i++) {
            cin >> x;
            v[i].resize(x);
            for (int& j : v[i]) cin >> j;
            v[i].emplace_back(i);
        }
        sort(v.begin(), v.end(), cmp);
        for (auto& j : v) {
            for (int k = 0; k < j.size() - 1; k++) {
                cout << j[k] << (k != j.size() - 2 ? ' ' : '\n');
            }
        }
    }
}
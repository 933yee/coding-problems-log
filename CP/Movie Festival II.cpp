#include <bits/stdc++.h>
using namespace std;

int n, k, a, b, cnt;
set<pair<int, int>> st;
vector<pair<int, int>> v;

bool cmp(pair<int, int>& a, pair<int, int>& b) {
    return a.second < b.second;
}

int main() {
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        v.push_back({a, b});
    }
    sort(v.begin(), v.end(), cmp);
    // for (auto i : v) {
    //     cout << i.first << ' ' << i.second << '\n';
    // }
    for (int i = 0; i < n; i++) {
        if (st.empty()) {
            st.insert({-v[i].second, 0});
        } else {
            auto p = st.lower_bound({-v[i].first, 0});
            if (p != st.end()) {
                st.insert({-v[i].second, p->second});
                st.erase(p);
            } else if (st.size() < k) {
                st.insert({-v[i].second, i});
            } else {
                cnt++;
            }
        }
    }
    cout << n - cnt;
}
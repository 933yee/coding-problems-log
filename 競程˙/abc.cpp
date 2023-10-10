#include <bits/stdc++.h>
using namespace std;
struct group {
    group() {}
    int size, mx, order;
    long long sum;
    vector<int> v;
};
vector<group> groups;
bool cmp(group& a, group& b) {
    if (a.sum != b.sum) return a.sum > b.sum;
    if (a.mx != b.mx) return a.mx > b.mx;
    if (a.size != b.size) return a.size > b.size;
    return a.order < b.order;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        groups.clear();
        for (int i = 0; i < n; i++) {
            group create;
            int sz, mx = -1, num;
            long long sum = 0;
            cin >> sz;
            for (int i = 0; i < sz; i++) {
                cin >> num;
                sum += num;
                create.v.emplace_back(num);
                mx = max(num, mx);
            }
            create.size = sz;
            create.mx = mx;
            create.sum = sum;
            create.order = i;
            groups.emplace_back(create);
        }
        sort(groups.begin(), groups.end(), cmp);
        for (auto& i : groups) {
            for (int j = 0; j < i.v.size(); j++) {
                cout << i.v[j] << ((j != i.v.size() - 1) ? ' ' : '\n');
            }
        }
    }
}
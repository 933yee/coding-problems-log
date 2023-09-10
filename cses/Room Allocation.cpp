#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define IOS                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
#define lowbit(x) ((x) & -(x))
const ll M = 1e9 + 7;

int n;
vvi v;
vi ans;
multimap<int, int> mp;

int main() {
    IOS;
    cin >> n;
    v.resize(n);
    ans.resize(n);
    for (int i = 0; i < n; i++) {
        v[i].resize(3);
        cin >> v[i][0] >> v[i][1];
        v[i][2] = i;
    }
    sort(v.begin(), v.end());

    for (int i = 0; i < n; i++) {
        auto p = mp.lower_bound(v[i][0]);
        if (p == mp.begin()) {
            ans[v[i][2]] = mp.size();
            mp.insert({v[i][1], ans[v[i][2]]});
        } else {
            p--;
            ans[v[i][2]] = p->second;
            mp.insert({v[i][1], p->second});
            mp.erase(p);
        }
    }
    cout << mp.size() << '\n';
    for (int& i : ans) cout << i + 1 << ' ';
}
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
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
vector<pii> v;

bool cmp(pii& a, pii& b) {
    return a.S < b.S;
}

int main() {
    IOS;
    cin >> n;
    v.resize(n);
    for (auto& i : v)
        cin >> i.F >> i.S;
    sort(v.begin(), v.end(), cmp);
    int ans = 1;
    int prev_end = v[0].S;
    for (int i = 1; i < n; i++) {
        if (prev_end <= v[i].F) {
            prev_end = v[i].S;
            ans++;
        }
    }
    cout << ans;
}

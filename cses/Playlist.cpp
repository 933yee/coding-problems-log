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

int n, cnt, ans;
vi v;
map<int, int> mp;

int main() {
    IOS;
    cin >> n;
    v.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    for (int p = 0, q = 0; q < n; q++) {
        if (mp.find(v[q]) != mp.end() && mp[v[q]] >= p) {
            p = mp[v[q]] + 1;
            cnt = q - p;
        }
        mp[v[q]] = q;
        cnt++;
        ans = max(ans, cnt);
    }
    cout << ans;
}
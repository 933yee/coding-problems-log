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
vector<ll> v;

int main() {
    IOS;
    cin >> n;
    v.resize(n);
    for (ll& i : v)
        cin >> i;

    ll ans = INT_MIN, cur = 0;
    for (ll& i : v) {
        ans = max(ans, cur + i);
        if (i + cur >= 0) {
            cur = i + cur;
        } else
            cur = 0;
    }
    cout << ans;
}
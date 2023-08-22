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
#define REP(i, a, b) for (int i = a; i <= b; i++)
const ll M = 1e9 + 7;

int main() {
    IOS int n, mid = 3;
    ll cur = 96, ret;
    int ans[] = {0, 6, 28, 96, 252};
    cin >> n;
    REP(i, 1, n) {
        if (i <= 5)
            cout << ans[i - 1] << '\n';
        else {
            cur += mid * 8 + 4 * 4 + 6 * 4;
            mid += 2;
            ret = (ll)i * i * (i * i - 1) / 2 - cur / 2;
            cout << ret << '\n';
        }
    }
}
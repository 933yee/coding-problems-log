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

char mp[10][10];
ll ans;

void dfs(int l, int m, int r, int n) {
    if (n > 8) {
        ans++;
        return;
    }
    for (int i = 1; i <= 8; i++) {
        if (mp[n][i - 1] != '*' && ((l | m | r) & (1 << (i - 1))) == 0) {
            ll a = l | (1 << (i - 1));
            ll b = m | (1 << (i - 1));
            ll c = r | (1 << (i - 1));
            dfs((a << 1), b, (c >> 1), n + 1);
        }
    }
}

int main() {
    IOS;
    for (int i = 1; i <= 8; i++) {
        cin >> mp[i];
    }
    dfs(0, 0, 0, 1);
    cout << ans << '\n';
}
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

int t, l, r;

int main() {
    IOS;

    cin >> t;
    while (t--) {
        cin >> l >> r;
        if ((l + r) % 3 || max(l, r) > 2 * min(l, r))
            cout << "NO\n";
        else
            cout << "YES\n";
    }
}
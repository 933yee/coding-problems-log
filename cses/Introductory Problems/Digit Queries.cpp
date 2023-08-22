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

ll q, n;

int main() {
    IOS;
    cin >> q;
    while (q--) {
        cin >> n;
        ll base = 9;
        ll dup = 1;
        while (n > base * dup) {
            n -= base * dup;
            base *= 10;
            dup++;
        }
        ll num = (base / 9 + (n - 1) / dup);
        ll div = 1, idx = dup - (n - 1) % dup;
        while (--idx) div *= 10;
        cout << num / div % 10 << "\n";
    }
}
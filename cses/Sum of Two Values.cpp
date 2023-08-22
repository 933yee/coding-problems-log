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

vector<pii> v;
int n, x;

int main() {
    IOS;
    cin >> n >> x;
    v.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].F;
        v[i].S = i + 1;
    }
    sort(v.begin(), v.end());

    int l = 0, r = n - 1;
    while (l < r) {
        int sum = v[l].F + v[r].F;
        if (sum > x) {
            r--;
        } else if (sum < x) {
            l++;
        } else {
            cout << v[l].S << ' ' << v[r].S;
            return 0;
        }
    }
    cout << "IMPOSSIBLE";
}
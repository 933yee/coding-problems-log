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

int n, ans;
vi v;

int main() {
    IOS;
    cin >> n;
    v.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        v[x] = i;
    }
    int prev = 0;
    for (int i = 1; i <= n; i++) {
        if (v[i] < prev) ans++;
        prev = v[i];
    }
    cout << ans + 1;
}

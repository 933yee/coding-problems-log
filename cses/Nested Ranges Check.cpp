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
vector<pii> ans;

int main() {
    IOS;
    cin >> n;
    ans.resize(n);

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        v.PB({a, b, i});
    }
    sort(v.begin(), v.end(), [](vi& a, vi& b) {
        if (a[0] == b[0])
            return a[1] > b[1];
        else
            return a[0] < b[0];
    });
    int mn = v[n - 1][1];
    for (int i = n - 2; i >= 0; i--) {
        if (v[i][1] >= mn)
            ans[v[i][2]].F = 1;
        else
            mn = v[i][1];
    }
    int mx = v[0][1];
    for (int i = 1; i < n; i++) {
        if (mx >= v[i][1])
            ans[v[i][2]].S = 1;
        else
            mx = v[i][1];
    }
    for (int i = 0; i < n; i++) cout << ans[i].F << ' ';
    cout << '\n';
    for (int i = 0; i < n; i++) cout << ans[i].S << ' ';
}
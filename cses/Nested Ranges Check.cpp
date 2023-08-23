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
set<int> st;

bool cmp(pii& a, pii& b) {
    if (a.F == b.F)
        return a.S > b.S;
    else
        return a.F < b.F;
}

int main() {
    IOS;
    cin >> n;
    vvi ans(2, vi(n));

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        v.PB({a, b, i});
    }
    sort(v.begin(), v.end(), cmp);
    // for (pii& i : v) {
    //     cout << "(" << i.F << "," << i.S << ")" << '\n';
    // }
    for (int i = 0; i < n; i++) {
    }
}
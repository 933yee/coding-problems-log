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

vi v;
int n;

int main() {
    IOS;
    cin >> n;
    v.resize(n);
    for (int& i : v)
        cin >> i;

    sort(v.begin(), v.end());

    int mid = v[n / 2];
    ll ans = 0;
    for (int& i : v)
        ans += abs(mid - i);

    cout << ans;
}
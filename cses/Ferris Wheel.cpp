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

int n, x;
vi v;

int main() {
    IOS;
    cin >> n >> x;
    v.resize(n);
    for (int& i : v)
        cin >> i;

    sort(v.begin(), v.end());
    int l = 0, r = v.size() - 1, ans = 0;
    while (l < r) {
        int sum = v[l] + v[r];
        if (sum > x) {
            ans++;
            r--;
        } else {
            l++;
            r--;
            ans++;
        }
    }
    cout << ans + (l == r);
}
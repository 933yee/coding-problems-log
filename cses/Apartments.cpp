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

int n, m, k;
vi v1, v2;

int main() {
    IOS;
    cin >> n >> m >> k;
    v1.resize(n);
    v2.resize(m);
    for (int& i : v1)
        cin >> i;

    for (int& i : v2)
        cin >> i;

    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());

    int p1 = 0, p2 = 0, ans = 0;
    while (p1 < v1.size() && p2 < v2.size()) {
        if (v1[p1] - k <= v2[p2] && v1[p1] + k >= v2[p2]) {
            p1++;
            p2++;
            ans++;
        } else if (v1[p1] < v2[p2]) {
            p1++;
        } else
            p2++;
    }
    cout << ans;
}
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

int n, m, cnt = 1;
vi v1, v2;

int main() {
    IOS;
    cin >> n >> m;
    v1.resize(n + 1);
    v2.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v1[i];
        v2[v1[i]] = i;
    }
    int prev = 0;
    for (int i = 1; i <= n; i++) {
        if (v2[i] < prev) cnt++;
        prev = v2[i];
    }
    while (m--) {
        int a, b;
        cin >> a >> b;

        int num1 = v1[a], num2 = v1[b];
        int mn = min(num1, num2), mx = max(num1, num2);
        if (mx - mn != 1) {
            if (v2[mn] > v2[mn + 1]) cnt--;
            if (v2[mx - 1] > v2[mx]) cnt--;
        } else if (v2[mn] > v2[mn + 1])
            cnt--;
        if (mn - 1 != 0 && v2[mn - 1] > v2[mn]) cnt--;
        if (mx + 1 <= n && v2[mx] > v2[mx + 1]) cnt--;
        swap(v2[num1], v2[num2]);
        swap(v1[a], v1[b]);
        if (mx - mn != 1) {
            if (v2[mn] > v2[mn + 1]) cnt++;
            if (v2[mx - 1] > v2[mx]) cnt++;
        } else if (v2[mn] > v2[mn + 1])
            cnt++;
        if (mn - 1 != 0 && v2[mn - 1] > v2[mn]) cnt++;
        if (mx + 1 <= n && v2[mx] > v2[mx + 1]) cnt++;
        cout << cnt << '\n';
    }
}

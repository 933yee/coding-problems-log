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

int n;
vi weight(20), seen(20);
ll sum, subsum, ans = INT_MAX;

void dfs(int cnt, int idx) {
    ans = min(ans, abs(sum - 2 * subsum));
    for (int i = idx; i < n; i++) {
        if (!seen[i]) {
            seen[i] = true;
            subsum += weight[i];
            dfs(cnt - 1, i + 1);
            subsum -= weight[i];
            seen[i] = false;
        }
    }
}

int main() {
    IOS;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> weight[i];
        sum += weight[i];
    }

    dfs(n, 0);
    cout << ans;
}
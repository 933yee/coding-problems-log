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

set<pair<int, int>> st;
int n;

int main() {
    IOS;
    cin >> n;
    while (n--) {
        int x, y;
        cin >> x >> y;
        st.insert({x, 1});
        st.insert({y, -1});
    }

    int cnt = 0, ans = 0;
    for (auto& i : st) {
        cnt += i.S;
        ans = max(cnt, ans);
    }
    cout << ans;
}
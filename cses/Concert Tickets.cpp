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

multiset<int> st;
vi v;
int n, m;

int main() {
    IOS;
    cin >> n >> m;
    while (n--) {
        int x;
        cin >> x;
        st.insert(x);
    }
    v.resize(m);
    for (int& i : v)
        cin >> i;

    for (int& i : v) {
        auto p = st.upper_bound(i);
        if (p != st.begin()) {
            p--;
            cout << *p << '\n';
            st.erase(p);
        } else {
            cout << -1 << '\n';
        }
    }
}
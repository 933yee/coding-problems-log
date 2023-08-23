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
multiset<int> st;

int main() {
    IOS;
    cin >> n;
    while (n--) {
        int x;
        cin >> x;
        auto p = st.upper_bound(x);
        if (p != st.end())
            st.erase(p);
        st.insert(x);
    }
    cout << st.size();
}
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

int x, n;
set<int> st;
multiset<int> ans;

int main() {
    IOS;
    cin >> x >> n;
    st.insert(0);
    st.insert(x);
    ans.insert(x);
    while (n--) {
        int a;
        cin >> a;
        st.insert(a);
        auto p = st.find(a);
        auto q = p;
        p--, q++;
        int len = (*q) - (*p);
        ans.erase(ans.find(len));
        ans.insert((*q) - a);
        ans.insert(a - (*p));

        auto last = --ans.end();
        cout << *last << '\n';
    }
}
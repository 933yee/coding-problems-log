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
#define REP(i, a, b) for (int i = a; i <= b; i++)
const ll M = 1e9 + 7;

ll n;

int main() {
    IOS;
    while (cin >> n) {
        ll sum = (1 + n) * n / 2;
        if (sum & 1)
            cout << "NO\n";
        else {
            sum /= 2;
            vi v1, v2;
            for (int i = n; i >= 1; i--) {
                if (sum >= i) {
                    v1.PB(i);
                    sum -= i;
                } else {
                    v2.PB(i);
                }
            }
            cout << "YES\n";
            cout << v1.size() << '\n';
            for (int& i : v1)
                cout << i << ' ';
            cout << '\n';
            cout << v2.size() << '\n';
            for (int& i : v2)
                cout << i << ' ';
            cout << '\n';
        }
    }
}
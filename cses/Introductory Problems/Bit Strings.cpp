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
ll sum = 1;

ll f(ll n) {
    if (n == 0) return 1;
    ll cal = f(n / 2) % M;
    if (n & 1)
        return cal * cal % M * 2 % M;
    else
        return cal * cal % M;
}

int main() {
    IOS;
    cin >> n;
    cout << f(n) % M;
}
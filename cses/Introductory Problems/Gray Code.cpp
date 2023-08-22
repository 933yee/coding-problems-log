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

int main() {
    IOS;
    cin >> n;
    for (int i = 0; i < (1 << n); i++) {
        for (int j = n - 1; j >= 0; j--) {
            cout << (((i >> j) ^ (i >> (j + 1))) & 1);
        }
        cout << '\n';
    }
}
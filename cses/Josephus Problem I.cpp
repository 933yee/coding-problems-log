#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
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

int n, cnt;
vector<int> v1, v2;

int main() {
    IOS;
    cin >> n;
    for (int i = 2; i <= n; i++)
        v1.PB(i);
    v1.PB(1);

    while (!v1.empty()) {
        for (int i = 0; i < v1.size(); i++) {
            if (i & 1)
                v2.PB(v1[i]);
            else
                cout << v1[i] << ' ';
        }
        if (v1.size() & 1) {
            v1.clear();
            for (int i = 1; i < v2.size(); i++)
                v1.PB(v2[i]);
            if (!v2.empty())
                v1.PB(v2[0]);
        } else
            v1 = v2;
        v2.clear();
    }
}
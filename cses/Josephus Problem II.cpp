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

int n, k;
vi v1, v2;

int main() {
    IOS;
    cin >> n >> k;
    int f = k % n + 1;
    for (int i = f; i <= n; i++) v1.PB(i);
    for (int i = 1; i < f && i <= n; i++) v1.PB(i);
    while (!v1.empty()) {
        for (int i = 0; i < v1.size(); i++) {
            if (i % (k + 1) == 0)
                cout << v1[i] << ' ';
            else
                v2.PB(v1[i]);
        }
        int mod = (v1.size() - 1) % (k + 1);
        v1.clear();
        int t = k - mod;
        if (t >= v2.size() && v2.size() != 0) t %= v2.size();
        for (int i = t; i < v2.size(); i++) v1.PB(v2[i]);
        for (int i = 0; i < t && i < v2.size(); i++) v1.PB(v2[i]);
        v2.clear();
    }
}
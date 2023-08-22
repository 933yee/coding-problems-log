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
vi v;

int main() {
    IOS;
    cin >> n;
    v.resize(n);
    for (int& i : v)
        cin >> i;

    sort(v.begin(), v.end());
    int cnt = 1, prev_num = v[0];
    for (int i = 1; i < v.size(); i++) {
        if (v[i] != v[i - 1]) {
            cnt++;
        }
        prev_num = v[i];
    }
    cout << cnt;
}
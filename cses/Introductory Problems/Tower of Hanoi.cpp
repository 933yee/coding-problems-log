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
ll cur = 1;
void hanoi(int from, int mid, int to, int n) {
    if (n == 1) {
        cout << from << ' ' << to << '\n';
        return;
    }
    hanoi(from, to, mid, n - 1);
    hanoi(from, mid, to, 1);
    hanoi(mid, from, to, n - 1);
}

int main() {
    IOS;
    cin >> n;
    for (int i = 1; i < n; i++)
        cur = cur * 2 + 1;
    cout << cur << '\n';
    hanoi(1, 2, 3, n);
}
#include <bits/stdc++.h>
using namespace std;

int t, x, k;
int calc(int x) {
    int cnt = 0;
    while (x) {
        cnt += x % 10;
        x /= 10;
    }
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> x >> k;
        while (calc(x) % k != 0) {
            x++;
        }
        cout << x << '\n';
    }
}
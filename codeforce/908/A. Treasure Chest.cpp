#include <bits/stdc++.h>
using namespace std;
int t, x, y, k;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> x >> y >> k;
        if (x >= y) {
            cout << x << '\n';
        } else if (x + k >= y)
            cout << y << '\n';
        else {
            cout << y + y - x - k << '\n';
        }
    }
}

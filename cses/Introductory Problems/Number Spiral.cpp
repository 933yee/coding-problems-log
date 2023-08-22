#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll t;
ll row, col, ans;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    cin >> t;
    while (t--) {
        cin >> row >> col;
        if (row >= col) {
            if (row & 1)
                ans = (row - 1) * (row - 1) + col;
            else
                ans = row * row - (col - 1);
        } else {
            if (col & 1)
                ans = col * col - (row - 1);
            else
                ans = (col - 1) * (col - 1) + row;
        }
        cout << ans << '\n';
    }
}
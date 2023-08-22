#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int n;
ll pre, cur, ans;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    cin >> n;
    cin >> pre;
    while (--n) {
        cin >> cur;
        if (pre > cur) {
            ans += pre - cur;
            pre = pre;
        } else
            pre = cur;
    }
    cout << ans;
}
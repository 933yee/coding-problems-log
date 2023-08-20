#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll a;
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    cin >> a;
    while (a != 1) {
        cout << a << ' ';
        if (a & 1) {
            a *= 3;
            ++a;
        } else
            a /= 2;
    }
    cout << a;
    return 0;
}
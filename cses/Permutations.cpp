#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int n;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    cin >> n;
    if (n == 2 || n == 3) {
        cout << "NO SOLUTION";
    } else {
        for (int i = 2; i <= n; i += 2)
            cout << i << ' ';
        for (int i = 1; i <= n; i += 2)
            cout << i << ' ';
    }
}
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int n, cnt[200005], a;
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        cin >> a;
        cnt[a]++;
    }
    for (int i = 1; i <= n; i++) {
        if (cnt[i] == 0)
            cout << i;
    }
}
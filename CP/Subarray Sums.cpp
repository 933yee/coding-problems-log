#include <bits/stdc++.h>
using namespace std;

int n, x;
long long sum, a, ans;
map<long long, int> mp;

int main() {
    mp[0] = 1;
    cin >> n >> x;
    while (n--) {
        cin >> a;
        sum += a;
        ans += mp[sum - x];
        mp[sum]++;
    }
    cout << ans;
}
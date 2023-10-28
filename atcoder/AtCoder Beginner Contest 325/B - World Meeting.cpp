#include <bits/stdc++.h>
using namespace std;

int N, a, b;
vector<pair<int, int>> v;
int ans = -1;
int main() {
    cin >> N;
    while (N--) {
        cin >> a >> b;
        v.push_back({a, b});
    }
    for (int i = 0; i <= 23; i++) {
        int sum = 0;
        for (auto& j : v) {
            int t = (j.second + i) % 24;
            if (t <= 17 && t >= 9) sum += j.first;
        }
        ans = max(ans, sum);
    }
    cout << ans;
}
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
string s;
int cur, cnt, ans;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    cin >> s;
    cur = s[0];
    cnt = 1;
    ans = 1;
    for (int i = 1; i < s.size(); i++) {
        if (s[i] == s[i - 1]) {
            cnt++;
            ans = max(ans, cnt);
        } else {
            cur = s[i];
            cnt = 1;
        }
    }
    cout << ans;
}
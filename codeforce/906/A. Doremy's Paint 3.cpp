#include <bits/stdc++.h>
using namespace std;

int t, n, x;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n;
        map<int, int> mp;
        while (n--) {
            cin >> x;
            mp[x]++;
        }
        if (mp.size() > 2) {
            cout << "No\n";
        } else if (mp.size() == 1) {
            cout << "Yes\n";
        } else {
            auto k = mp.begin();
            auto p = mp.begin();
            p++;
            if (abs(k->second - p->second) <= 1)
                cout << "Yes\n";
            else
                cout << "No\n";
        }
    }
}
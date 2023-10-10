#include <bits/stdc++.h>
using namespace std;

int t, n, q;
int rec[200005];
vector<int> F, B, B2;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n >> q;
        memset(rec, 0, sizeof(rec));
        F.clear();
        B.clear();
        B2.clear();
        while (q--) {
            char a;
            int b;
            cin >> a >> b;
            if (a == 'H') {
                F.emplace_back(b);
                rec[b] = 'F';
            } else {
                B.emplace_back(b);
                rec[b] = 'B';
            }
        }
        for (auto it = F.rbegin(); it != F.rend(); it++)
            if (rec[*it] == 'F') {
                cout << *it << ' ';
                rec[*it] = -1;
            }
        for (int i = 1; i <= n; i++)
            if (rec[i] == 0)
                cout << i << ' ';
        for (auto it = B.rbegin(); it != B.rend(); it++)
            if (rec[*it] == 'B') {
                B2.emplace_back(*it);
                rec[*it] = -1;
            }
        for (auto it = B2.rbegin(); it != B2.rend(); it++)
            cout << *it << ' ';
        cout << '\n';
    }
}
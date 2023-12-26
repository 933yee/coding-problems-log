#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> v(1000005);

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        v[x]++;
    }

    for (int i = 1e6; i >= 1; i--) {
        int cnt = 0;
        for (int j = i; j < 1e6 + 1; j += i) {
            cnt += v[j];
        }
        if (cnt >= 2) {
            cout << i;
            return 0;
        }
    }
}
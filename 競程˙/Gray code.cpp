#include <bits/stdc++.h>
using namespace std;

int n;

int main() {
    cin >> n;
    for (int i = 0; i < (1 << n); i++) {
        int x = i >> 1;
        for (int j = n - 1; j >= 0; j--) {
            cout << (((x >> j) ^ (i >> j)) & 1);
        }
        cout << '\n';
    }
}
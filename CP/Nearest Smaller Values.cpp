#include <bits/stdc++.h>
using namespace std;

stack<pair<int, int>> stk;
int n, x;

int main() {
    cin >> n;
    stk.push({0, 0});
    for (int i = 1; i <= n; i++) {
        cin >> x;
        while (!stk.empty() && stk.top().first >= x) {
            stk.pop();
        }
        cout << stk.top().second << ' ';
        stk.push({x, i});
    }
}
#include <bits/stdc++.h>
using namespace std;

int n, x;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    priority_queue<int> left;
    priority_queue<int, vector<int>, greater<int>> right;
    left.push(INT_MIN);
    right.push(INT_MAX);

    cin >> n;

    while (n--) {
        cin >> x;
        if (x <= left.top())
            left.push(x);
        else
            right.push(x);

        if (left.size() >= right.size() + 2) {
            right.push(left.top());
            left.pop();
        } else if (right.size() >= left.size() + 1) {
            left.push(right.top());
            right.pop();
        }
        cout << left.top() << ' ';
    }
}
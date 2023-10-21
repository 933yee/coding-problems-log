#include <bits/stdc++.h>
using namespace std;

int N, a;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    queue<int> q;
    priority_queue<int, vector<int>, greater<int>> pq;
    cin >> N;
    while (N--) {
        cin >> a;
        if (a == 1) {
            cin >> a;
            q.push(a);
        } else if (a == 2) {
            if (!pq.empty()) {
                cout << pq.top() << '\n';
                pq.pop();
            } else {
                cout << q.front() << '\n';
                q.pop();
            }
        } else {
            while (!q.empty()) {
                pq.push(q.front());
                q.pop();
            }
        }
    }
}
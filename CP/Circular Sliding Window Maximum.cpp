#include <bits/stdc++.h>
using namespace std;
int N, K, x;
vector<int> v;
deque<pair<int, int>> dq;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        cin >> x;
        v.emplace_back(x);
    }
    for (int i = 0; i < K - 1; i++) {
        v.emplace_back(v[i]);
        while (!dq.empty() && v[i] > dq.back().first) {
            dq.pop_back();
        }
        dq.push_back({v[i], i});
    }
    for (int i = K - 1; i < N + K - 1; i++) {
        while (!dq.empty() && v[i] > dq.back().first) {
            dq.pop_back();
        }
        dq.push_back({v[i], i});
        if (dq.front().second < i - K + 1) dq.pop_front();
        cout << dq.front().first << ' ';
    }
}
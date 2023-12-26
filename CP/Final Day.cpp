#include <bits/stdc++.h>
using namespace std;

int N, K;
vector<int> v, v2;

int main() {
    cin >> N >> K;

    for (int i = 0; i < N; i++) {
        int sum = 0, x;
        for (int j = 0; j < 3; j++) {
            cin >> x;
            sum += x;
        }
        v.push_back(sum);
        v2.push_back(sum);
    }
    sort(v.begin(), v.end());
    // for (int& i : v2) {
    //     cout << i << '\n';
    // }
    for (int& i : v2) {
        auto p = upper_bound(v.begin(), v.end(), i + 300);
        p--;
        // cout << v.end() - p << '\n';
        if (v.end() - p <= K)
            cout << "Yes\n";
        else
            cout << "No\n";
    }
}
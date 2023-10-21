#include <bits/stdc++.h>
using namespace std;

int n, k;
long long l = 0, r = LONG_LONG_MAX;
vector<long long> v;

bool isvalid(long long target) {
    int count = 0;
    long long sum = 0;
    for (long long& i : v) {
        sum += i;
        if (sum > target) {
            count++;
            sum = i;
        }
    }
    return count <= k - 1;
}

int main() {
    cin >> n >> k;
    v.resize(n);
    for (long long& i : v) {
        cin >> i;
        l = max(i, l);
    }
    while (l < r) {
        long long m = l + (r - l) / 2;
        if (isvalid(m)) {
            r = m;
        } else {
            l = m + 1;
        }
    }
    cout << l;
}
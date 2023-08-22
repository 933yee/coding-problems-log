#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define IOS                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
#define lowbit(x) ((x) & -(x))
const ll M = 1e9 + 7;

string s, cur;
vector<string> v;
vector<bool> seen;

void dfs(int n) {
    if (n == s.size()) {
        v.PB(cur);
        return;
    }
    vector<bool> used(26);
    for (int i = 0; i < s.size(); i++) {
        if (!seen[i] && !used[s[i] - 'a']) {
            seen[i] = used[s[i] - 'a'] = true;
            cur.PB(s[i]);
            dfs(n + 1);
            cur.pop_back();
            seen[i] = false;
        }
    }
}

int main() {
    IOS;
    cin >> s;
    seen.resize(s.size());
    sort(s.begin(), s.end());
    dfs(0);
    cout << v.size() << '\n';
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << '\n';
    }
}
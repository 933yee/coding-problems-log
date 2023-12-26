#include <bits/stdc++.h>
using namespace std;

string s, cur;
vector<string> ans;
vector<bool> seen;

void dfs(int cnt) {
    if (cnt == s.size()) {
        ans.emplace_back(cur);
        return;
    }
    vector<bool> used(26);
    for (int i = 0; i < s.size(); i++) {
        if (!seen[i] && !used[s[i] - 'a']) {
            used[s[i] - 'a'] = true;
            seen[i] = true;
            cur.push_back(s[i]);
            dfs(cnt + 1);
            cur.pop_back();
            seen[i] = false;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> s;
    seen.resize(s.size());
    sort(s.begin(), s.end());
    dfs(0);
    cout << ans.size() << '\n';
    for (string& s : ans) {
        cout << s << '\n';
    }
}
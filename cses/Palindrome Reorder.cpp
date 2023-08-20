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

int cnt[26];
string s, ans;
char oddChar;

int main() {
    IOS;
    cin >> s;
    for (char& c : s)
        cnt[c - 'A']++;

    int odd = 0;
    for (int i = 0; i < 26; i++) {
        if (cnt[i]) {
            if (cnt[i] & 1) {
                if (odd) {
                    cout << "NO SOLUTION";
                    return 0;
                }
                odd = 1;
                oddChar = i + 'A';
            }
            for (int j = 0; j < cnt[i] / 2; j++)
                ans += i + 'A';
        }
    }
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i];
    if (odd) cout << oddChar;
    for (int i = ans.size() - 1; i >= 0; i--)
        cout << ans[i];
}
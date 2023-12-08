#include <bits/stdc++.h>
using namespace std;

int N, target, x, steps;
vector<int> jugs, state;
queue<vector<int>> q;
set<vector<int>> seen;
bool found = false;

bool possible() {
    int mx = 0, G = jugs[0];
    for (int i = 0; i < N; i++) {
        mx = max(mx, jugs[i]);
        G = __gcd(G, jugs[i]);
    }
    if (target % G != 0 || target > mx)
        return false;
    return true;
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> x;
        jugs.push_back(x);
    }
    cin >> target;
    if (!possible()) {
        cout << -1;
        return 0;
    }
    if (target == 0) {
        cout << 0;
        return 0;
    }
    state.resize(N);
    q.push(state);
    seen.insert(state);

    while (!q.empty()) {
        steps++;
        for (int k = q.size(); k--;) {
            auto cur = q.front();
            q.pop();

            // for (int p : cur)
            //     cout << p << ' ';
            // cout << '\n';
            for (int i = 0; i < N; i++) {
                int rec = cur[i];
                // fill
                cur[i] = jugs[i];
                if (cur[i] == target) {
                    found = true;
                    break;
                }
                if (!seen.count(cur)) {
                    seen.insert(cur);
                    q.push(cur);
                }
                // empty
                cur[i] = 0;
                if (!seen.count(cur)) {
                    seen.insert(cur);
                    q.push(cur);
                }
                cur[i] = rec;
            }
            // transfer
            for (int i = 0; i < N; i++) {
                for (int j = i + 1; j < N; j++) {
                    int rec1 = cur[i];
                    int rec2 = cur[j];
                    cur[i] = min(jugs[i], rec1 + rec2);
                    cur[j] = max(0, rec1 + rec2 - jugs[i]);
                    if (cur[i] == target || cur[j] == target) {
                        found = true;
                        break;
                    }
                    if (!seen.count(cur)) {
                        seen.insert(cur);
                        q.push(cur);
                    }
                    cur[j] = min(jugs[j], rec1 + rec2);
                    cur[i] = max(0, rec1 + rec2 - jugs[j]);
                    if (cur[i] == target || cur[j] == target) {
                        found = true;
                        break;
                    }
                    if (!seen.count(cur)) {
                        seen.insert(cur);
                        q.push(cur);
                    }
                    cur[i] = rec1;
                    cur[j] = rec2;
                }
                if (found) break;
            }
            if (found) break;
        }
        if (found) break;
    }
    if (found) {
        cout << steps;
    } else {
        cout << -1;
    }
}
#include <bits/stdc++.h>
using namespace std;

int n, m, age;
string name, pos;
map<string, int> table = {
    {"elder", 1},
    {"nursy", 2},
    {"kit", 3},
    {"warrior", 4},
    {"appentice", 5},
    {"medicent", 6},
    {"deputy", 7},
    {"leader", 8},
};
vector<tuple<string, string, int>> v;

bool cmp(tuple<string, string, int>& a, tuple<string, string, int>& b) {
    int age1, age2;
    string name1, name2, pos1, pos2;
    tie(name1, pos1, age1) = a;
    tie(name2, pos2, age2) = b;
    if (pos1 != pos2) return table[pos1] < table[pos2];
    if (age1 == age2) return name1 < name2;
    if (pos1 == "appentice") return age1 < age2;
    return age1 > age2;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    while (cin >> n >> m) {
        v.clear();
        while (n--) {
            cin >> name >> pos >> age;
            v.push_back({name, pos, age});
        }
        sort(v.begin(), v.end(), cmp);
        int len = min(m, (int)v.size());
        for (int i = 0; i < len; i++) {
            cout << get<0>(v[i]) << '\n';
        }
    }
}
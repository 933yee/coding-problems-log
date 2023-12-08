#include <bits/stdc++.h>
using namespace std;

int n;
char c;
bool a, b;

int main() {
    cin >> n;
    while (n--) {
        cin >> c;
        if (a && c == 'b') {
            cout << "Yes";
            return 0;
        }
        if (b && c == 'a') {
            cout << "Yes";
            return 0;
        }
        if (c == 'a')
            a = true;
        else if (c == 'b')
            b = true;
        else
            a = b = false;
    }
    cout << "No";
}
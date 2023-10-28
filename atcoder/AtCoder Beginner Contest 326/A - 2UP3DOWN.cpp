#include <bits/stdc++.h>
using namespace std;
int X, Y;
int main() {
    cin >> X >> Y;
    if (X >= Y)
        cout << ((X - Y <= 3) ? "Yes" : "No");
    else
        cout << ((Y - X <= 2 || Y - X <= 2) ? "Yes" : "No");
}
#include <bits/stdc++.h>
using namespace std;

int N;

int main() {
    cin >> N;
    while (true) {
        int a = (N / 100) % 10;
        int b = (N / 10) % 10;
        int c = N % 10;
        if (a * b == c) {
            cout << N;
            break;
        }
        N++;
    }
}
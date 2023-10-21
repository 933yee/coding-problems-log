#include <bits/stdc++.h>
using namespace std;

int N;
double C;
vector<pair<double, double>> v;
double sum = 0, x_sum = 0;

int main() {
    cin >> N >> C;
    for (int i = 0; i < N; i++) {
        double a, b;
        cin >> a >> b;
        v.push_back({a, b});
        sum += pow((b - C), 2);
        x_sum += a;
    }
    double x = x_sum / N;
    for (int i = 0; i < N; i++) {
        sum += pow((x - (double)v[i].first), 2);
    }
    cout << fixed << setprecision(10) << sum;
}
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    double l, r;
    if (a > 0) {
        l = -10e9;
        r = 10e9;
    } else {
        l = 10e9;
        r = -10e9;
    }
    for (int i = 0; i < 1000; ++i) {
        double m = (l + r) / 2;
        if (a * m * m * m + b * m * m + c * m + d > 0) {
            r = m;
        } else {
            l = m;
        }
    }
    cout << setprecision(4) << fixed << r;
}

#include <iostream>
#include <cmath>
using namespace std;
int main() {
    cout << fixed;
    cout.precision(6);
    double c;
    cin >> c;
    double l = 0, r = c, m;
    for (int i = 0; i < 100; ++i) {
        m = (l + r) / 2;
        if (m * m + sqrt(m) > c) {
            r = m;
        } else {
            l = m;
        }
    }
    cout << l;
}
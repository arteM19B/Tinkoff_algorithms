#include <iostream>
using namespace std;
int main() {
    long long w, h, n;
    cin >> w >> h >> n;
    long long l = 0, r = max(w, h) * n;
    while (r - l > 1) {
        long long m = (r + l) / 2;
        if ((m / w) * (m / h) >= n) {
            r = m;
        } else {
            l = m;
        }
    }
    cout << r;
}
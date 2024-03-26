#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    long long n, k;
    cin >> n >> k;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    long long cnt = 0, l = 0, r = 1e18;
    while (r - l > 1) {
        cnt = 0;
        long long m = (l + r) / 2;
        for (int i = 0; i < n; ++i) {
            cnt += a[i] / m;
        }
        if (cnt < k) {
            r = m;
        } else {
            l = m;
        }
    }
    cout << l;
}

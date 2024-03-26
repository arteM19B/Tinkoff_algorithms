#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    int n, k;
    cin >> n >> k;
    vector<int> x(n);
    for (int i = 0; i < n; ++i) {
        cin >> x[i];
    }
    sort(x.begin(), x.end());
    for (int i = 0; i < k; ++i) {
        int q;
        cin >> q;
        int l = 0, r = n;
        while (r - l > 1) {
            int m = (r + l) / 2;
            if (x[m] > q) {
                r = m;
            } else {
                l = m;
            }
        }
        if (x[l] == q) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}

#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n, k;
    cin >> n >> k;
    vector<int> num(n);
    for (int i = 0; i < n; ++i) {
        cin >> num[i];
    }
    for (int i = 0; i < k; ++i) {
        int req;
        cin >> req;
        int r = n - 1, l = 0;
        while (r - l > 1) {
            int m = (l + r) / 2;
            if (num[m] > req) {
                r = m;
            } else {
                l = m;
            }
        }
        if (num[r] - req < req - num[l]) {
            cout << num[r] << endl;
        } else {
            cout << num[l] << endl;
        }
    }
    return 0;
}

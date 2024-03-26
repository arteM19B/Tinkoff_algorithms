#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    int n, k, u_b, l_b;
    cin >> n;
    vector<int> num1(n);
    for (int i = 0; i < n; ++i) {
        cin >> num1[i];
    }
    sort(num1.begin(), num1.end());
    cin >> k;
    vector<int> num2(k);
    for (int i = 0; i < k; ++i) {
        cin >> num2[i];
    }
    for (int i = 0; i < k; ++i) {
        int l = 0, r = n;
        while (r - l > 1) {
            int m = (r + l) / 2;
            if (num1[m] >= num2[i]) {
                r = m;
            } else {
                l = m;
            }
        }
        l_b = l;
        l = 0, r = n;
        while (r - l > 1) {
            int m = (r + l) / 2;
            if (num1[m] <= num2[i]) {
                l = m;
            } else {
                r = m;
            }
        }
        u_b = l;
        if (num1[u_b] == num2[i]) {
            if (u_b != l_b) {
                if (l_b == 0 && num1[l_b] == num2[i]) {
                    cout << u_b - l_b + 1 << " ";
                } else {
                    cout << u_b - l_b << " ";
                }
            } else {
                cout << 1 << " ";
            }
        } else {
            cout << 0 << " ";
        }
    }
    return 0;
}
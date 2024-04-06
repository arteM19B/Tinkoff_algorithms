#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;
    vector<int> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    int n;
    cin >> n;
    int c = (int) sqrt (n + .0) + 1;
    vector<int> add_b(n/c + 10, 0), sum_b(n/c + 10, 0);
    for (int i = 0; i < n; i++) {
        sum_b[i / c] += a[i];
        add_b[i / c] += a[i];
    }
    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        int pos = l;
        int sum = 0;
        while (pos < r) {
            if (pos % c != 0 || pos + c > r) {
                sum += a[pos] + add_b[pos];
                pos++;
            } else {
                sum += sum_b[pos / c] + add_b[pos / c] * c;
            }
        }
        cout << sum;
    }

}
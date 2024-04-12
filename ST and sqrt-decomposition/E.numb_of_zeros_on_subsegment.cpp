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
        a[i] == 0 ? a[i] = 1 : a[i] = 0;
    }

    int n;
    cin >> n;
    int c = (int) sqrt(N + .0) + 1;

    vector<int> count(N / c + 10, 0);
    for (int i = 0; i < N; i++) {
        count[i / c] += a[i];
    }
    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        l--; r--;
        int pos = l;
        int max_subarray = 0;

        while (pos <= r) {
            if (pos % c != 0 || pos + c > r) {
                max_subarray += a[pos];
                pos++;
            } else {
                max_subarray += count[pos / c];
                pos += c;
            }
        }
        cout << max_subarray << endl;
    }
    return 0;
}
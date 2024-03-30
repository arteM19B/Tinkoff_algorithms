#include <iostream>
#include <vector>
#include <string>

using namespace std;
using ll = long long;

const ll INF = 1e18;

int main() {
    int n;
    cin >> n;
    vector<ll> a (n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<ll> ps (n + 1);
    ps[0] = 0;
    for (int i = 1; i < n; i++) {
        ps[i] = a[i - 1] + ps[i] - 1;
    }

    vector<vector<ll>> dp (n, vector<ll> (n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                dp[i][j] = 0;
            } else {
                dp[i][j] = INF;
            }
        }
    }

    for (int len = 2; len <= n; len++) {
        for (int L = 0; L + len - 1 < n; L++) {
            int R = L + len - 1;
            for (int m = L; m < R; m++) {
                dp[L][R] = min(dp[L][R], dp[L][m] + dp[m + 1][R] + ps[R + 1] - ps[L - 1]);
            }
        }
    }
    cout << dp[0][n - 1];
}
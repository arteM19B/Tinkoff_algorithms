#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

const ll INF = 1e18;

int main() {
    int N;
    cin >> N;
    vector<vector<ll>> a(N, vector<ll> (N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> a[i][j];
            if (a[i][j] == 0) {
                a[i][j] = INF;
            }
        }
    }
    vector<vector<ll>> dp(N, vector<ll> (N, INF));
    dp[1][0] = 0;
    for (int i = 0; i < N; i++) {
        dp[1<<i][i] = 0;
    }

    for (int i = 0; i < (1<<N); i++) {
        for (int j = 0; j < N; j++) {
            if ((i & (i << j)) == 0) continue;
            for (int k = 0; k < N; k++) {
                if ((i & (1 << k)) > 0) continue;
                dp[i | (1 << k)][k] = min(dp[i | (1 << k)][k], dp[i][j] + a[j][k]);
            }
        }
    }

    ll ans = dp[(1 << N) - 1][0];
    for (int i = 1; i < N; i++) {
        ans = min(ans, dp[(1 << N) - 1][i]);
    }

    cout << ans;
}
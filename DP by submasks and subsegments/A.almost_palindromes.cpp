#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int N, k;
    cin >> N >> k;
    string s;
    cin >> s;

    vector<vector<int>> dp(N + 1, vector<int> (N + 1));

    for (int i = 1; i <= N; i++) {
        dp[i][i] = dp[i][i - 1] = 0;
    }

    for (int len = 2; len <= N; len++) {
        for (int L = 1; L + len - 1 <= N; L++) {
            int R = L + len - 1;
            dp[L][R] = dp[L + 1][R - 1] + (s[L - 1] != s[R - 1]);
        }
    }

    int ans = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (dp[j][i] <= k && j <= i) ans++;
//          я как-то криво сделал, поэтому пришлось проверять dp[j][i], а не dp[i][j] :(
        }
    }

    cout << ans;
}

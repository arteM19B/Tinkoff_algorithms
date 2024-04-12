#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
using ll = long long;

const int MAXN = 1e5;

bool is_heavy(int v, vector<vector<int>>& g, int& c) {
    return g[v].size() > c;
}

void add(int v, int x, vector<int>& heavy_d, vector<vector<int>>& g, vector<int>& a, int& c) {
    if (is_heavy(v, g, c)) {
        heavy_d[v] += x;
    } else {
        for (int to : g[v]) {
            a[to] += x;
        }
    }
}

int query(int v, vector<vector<int>>& g, vector<int>& heavy_d, vector<int>& a) {
    int ans = a[v];
    for (auto to : g[v]) {
        ans += heavy_d[to];
    }
    return ans;
}

int main() {
    vector<vector<int>> g(MAXN);
    vector<int> heavy_d(MAXN);
    vector<int> a(MAXN);
    int c;

    int N, m, q;
    cin >> N >> m >> q;
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    c = (int)sqrt(N + .0) + 1;

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    while (q--) {
        char type;
        cin >> type;
        if (type == '?') {
            int k;
            cin >> k;
            k--;
            cout << query(k, g, heavy_d, a) << endl;
        } else {
            int u, x;
            u--;
            cin >> u >> x;
            u--;
            add(u, x, heavy_d, g, a, c);
        }
    }

    return 0;
}
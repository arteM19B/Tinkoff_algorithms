#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
using ll = long long;

const int MAXN = 1e5;
vector<vector<int>> g(MAXN);

vector<int> heavy_d(MAXN);
vector<int> a(MAXN);
int c;

bool is_heavy(int v) {
    return g[v].size() > c;
}

void add(int v, int x) {
    if (is_heavy(v)) {
        heavy_d[v] += x;
    } else {
        for (int to : g[v]) {
            a[to] += x;
        }
    }
}

int query(int v) {
    int ans = a[v];
    for (auto to : g[v]) {
        ans += heavy_d[to];
    }
    return ans;
}

int main() {
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
            cout << query(k) << endl;
        } else {
            int u, x;
            cin >> u >> x;
            u--;
            add(u, x);
        }
    }

    return 0;
}

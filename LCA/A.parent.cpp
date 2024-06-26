// не заходит, wa на 2 тесте.


#include <iostream>
#include <vector>

using namespace std;

int timer = 0;
vector<vector<int>> g;
vector<int> tin, tout;

void dfs(int v) {
    tin[v] = timer++;
    for (int u : g[v]) {
        dfs(u);
    }
    tout[v] = timer++;
}

bool isParent(int v, int u) {
    if (tin[v] <= tin[u] && tout[u] <= tout[v]) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    int n;
    cin >> n;
    g.resize(n);
    tin.resize(n); tout.resize(n);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x == 0) continue;
        g[x - 1].push_back(i);
    }
    dfs(0);
    int k;
    cin >> k;
    for (int i = 0; i < k; i++) {
        int v, u;
        cin >> v >> u;
        v--;
        u--;
        cout << isParent(v, u) << "\n";
    }
}
//6
//0 1 1 2 3  3
//5
//4 1
//1 4
//3 6
//2 6
//6 5
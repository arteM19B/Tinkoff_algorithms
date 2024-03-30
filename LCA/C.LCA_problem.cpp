#include <iostream>
#include <vector>

using namespace std;

int n, l;
vector <vector<int>> g;
vector<int> tin, tout;
int timer;
vector < vector<int> > up;

void dfs (int v, int p = 0) {
    tin[v] = ++timer;
    up[v][0] = p;
    for (int i=1; i<=l; ++i)
        up[v][i] = up[up[v][i-1]][i-1];
    for (int to : g[v]) {
        if (to != p)
            dfs (to, v);
    }
    tout[v] = ++timer;
}

bool upper (int a, int b) {
    return tin[a] <= tin[b] && tout[a] >= tout[b];
}

int lca (int a, int b) {
    if (upper (a, b))  return a;
    if (upper (b, a))  return b;
    for (int i=l; i>=0; --i)
        if (!upper (up[a][i], b))
            a = up[a][i];
    return up[a][0];
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x == 0) continue;
        g[x - 1].push_back(i);
    }

    tin.resize (n),  tout.resize (n),  up.resize (n);
    l = 1;
    while ((1<<l) <= n)  ++l;
    for (int i=0; i<n; ++i)  up[i].resize (l+1);
    dfs (0);

    int k;
    cin >> k;

    while (k--) {
        int a, b; // текущий запрос
        cin >> a >> b;
        a--; b--;
        cout << lca (a, b); // ответ на запрос
    }

}
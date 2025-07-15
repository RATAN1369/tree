#include <bits/stdc++.h>
using namespace std;

vector<int> g[200100];
int subTrees[200100];
int n;

void dfs(int node, int parent) {
    subTrees[node] = 1;
    for (auto v : g[node]) {
        if (v != parent) {
            dfs(v, node);
            subTrees[node] += subTrees[v];
        }
    }
}

void solve() {
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    dfs(1, 0);
    
    long long ans = 0;
    for (int u = 1; u <= n; u++) {
        for (int v : g[u]) {
            if (subTrees[v] < subTrees[u]) { // v is child of u
                ans += 1LL * subTrees[v] * (n - subTrees[v]);
            }
        }
    }

    cout << ans << '\n';
}

int main() {
    solve();
    return 0;
}

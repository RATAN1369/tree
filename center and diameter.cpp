#include <bits/stdc++.h>
using namespace std;
#define ll long long 
vector<int> g[100100]; // Adjacency list for the tree
int dep[100100];       // Depth array
int par[100100];       // Parent array

void dfs(int node, int parent, int depth) {
    dep[node] = depth;
    par[node] = parent;

    for (auto v : g[node]) {
        if (v != parent) {
            dfs(v, node, depth + 1);
        }
    }
}
vector<int> ans;
vector<ll> final_ans;
void solve() {
    int n;
    cin >> n;

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    // First DFS from node 1 to find the farthest node y
    dfs(1, 0, 0);

    int y = 1;
    for (int i = 2; i <= n; i++) {
        if (dep[i] > dep[y]) {
            y = i;
        }
    }

    // Reset depth array before second DFS
    // fill(dep, dep + n + 1, 0);

    // Second DFS from node y to find the farthest node from y
    dfs(y, 0, 0);
     int z=y;
    int diameter = 0;
    for (int i = 1; i <= n; i++) {
       if(dep[i]>dep[z]){
         diameter=dep[i];
         z=i;
       }
    }

    // cout << diameter << endl;
    while(z!=y){
      ans.push_back(z);
      z=par[z];
    }
    ans.push_back(y);
    if(ans.size()%2==1){
      final_ans.push_back(ans[ans.size()/2]);
    }else{
       final_ans.push_back(ans[ans.size()/2-1]);
       final_ans.push_back(ans[ans.size()/2]);
    }
    // for(auto it: final_ans){
    //   cout<<it<<endl;
    // }

    cout<<ans.size()-1<<endl;
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}

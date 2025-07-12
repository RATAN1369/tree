//Code For Depth , Parent , Childs , Subtrees , LeafNodes

//---------------------------------------------------------------------------

#include <bits/stdc++.h>

using namespace std;



//int a[10] Array Of Integers 

vector<int> g[100100]; // Array Of Vectors

int dep[100100]; // Depth(Level)

int par[100100]; // Parent

bool isLeaf[100100]; 

int subTrees[100100];

int numChild[100100];



void dfs(int node,int parent,int depth)

{

  dep[node] = depth;

  par[node] = parent;

   

  subTrees[node] = 1; 

   

  numChild[node] = 0;

  for(auto v:g[node])

  {

    if(v!=parent) // This Means That's A Child

    {

      numChild[node]++;

      dfs(v,node,depth+1);

      subTrees[node]+=subTrees[v];

    }

  }

  if(numChild[node]==0)

  {

    isLeaf[node]=1;

  }

}



void solve()

{

  int n; // n Nodes

  cin>>n;

  for(int i=0;i<n-1;i++) // n-1 Edges

  {

    int a,b;

    cin>>a>>b;

    g[a].push_back(b);

    g[b].push_back(a);

  }

  dfs(1,0,0); // For First Node , Keeping 0 As The Parent , 0 Level(Depth)

  cout<<"Node\tDepth\tParent\tLeaf?\tSubtreeSize\tChildren\n";

  for(int i = 1; i <= n; i++) 

  {

    cout<< i << "\t" << dep[i] << "\t" << par[i] << "\t"

       << isLeaf[i] << "\t" << subTrees[i] << "\t\t" << numChild[i] << "\n";

  }



}



int main() 

{

  solve();

  return 0;

}


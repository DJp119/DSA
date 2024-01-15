#include<bits/stdc++.h>

int parent_node(vector<int>& parent,int node){
  if(parent[node]==node){
    return node;
  }
  return parent[node]=parent_node(parent,parent[node]);
}

void union_set(int u,int v,vector<int>&rank,vector<int>&parent){
  u=parent_node(parent,u);
  v=parent_node(parent,v);
  if(rank[u]<rank[v]){
    parent[u]=v;
  }else if(rank[v]<rank[u]){
    parent[v]=u;
  }else{
    parent[v]=u;
    rank[u]++;
  }
}

bool cmp(vector<int>&a,vector<int>&b){
  return a[2]<b[2];
}

int minimumSpanningTree(vector<vector<int>>& edges, int n)
{
  /*
    Don't write main().
    Don't read input, it is passed as function argument.    
    No need to print anything.
    Taking input and printing output is handled automatically.
  */
  vector<int> rank(n);
  vector<int> parent(n);
  for(int i=0;i<n;i++){
    parent[i]=i;
    rank[i]=0;
  }
  sort(edges.begin(),edges.end(),cmp);
  int ans=0;
  for(int i=0;i<edges.size();i++){
    int u=parent_node(parent,edges[i][0]);
    int v=parent_node(parent,edges[i][1]);
    int w=edges[i][2];
    if(u!=v){
      ans+=w;
      union_set(u,v,rank,parent);
    }
  }
  return ans;
}

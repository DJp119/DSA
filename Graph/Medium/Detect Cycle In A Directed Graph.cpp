#include <unordered_map>
#include <queue>
#include <list>
bool checkCycleDFS(int node,unordered_map<int,bool>&visited,unordered_map<int,bool>&dfsVisited,unordered_map<int,list<int>>&adj){
  visited[node]=true;
  dfsVisited[node]=true;

  for(auto neighbour : adj[node]){
    if(!visited[neighbour]){
      bool cycleDetected = checkCycleDFS(neighbour,visited,dfsVisited, adj);
      if(cycleDetected) return true;
    }
    else if(dfsVisited[neighbour]){
      // visited one
        return true;
    }
  }
  dfsVisited[node]=false;
  return false;
} 
int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  // create adj list
  unordered_map<int,list<int>>adj;
  for(int i=0;i<edges.size();i++){
    int u=edges[i].first;
    int v=edges[i].second;
  // because of directed graph
    adj[u].push_back(v);
  }
  // call dfs of all components
  unordered_map<int,bool>visited ;
  unordered_map<int,bool>dfsVisited;
  for(int i=1;i<=n;i++){
    if(!visited[i]){
      bool cycleFound=checkCycleDFS(i,visited,dfsVisited,adj);
      if(cycleFound) return true;
    }
  }
  return false;
}



// BFS Method Modified Kahn Algo 
#include <unordered_map>
#include <queue>
#include <list>
int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  
  unordered_map<int,list<int>>adj;
      
      for(int i=0;i<edges.size();i++){
        int u = edges[i].first -1;
        int v = edges[i].second -1;

        adj[u].push_back(v);
    }
  vector<int>indegree(n);
  for(auto i:adj){
    for(auto j:i.second) indegree[j]++;
  }

  queue<int>q;
  for(int i=0;i<n;i++){
    if(indegree[i]==0) q.push(i);
  }
  int cnt =0;
  while(!q.empty()){
    int frontNode = q.front();
    // inc count 
    cnt++;
    q.pop();
    for(auto neighbour : adj[frontNode]){
      indegree[neighbour]--;
      if(indegree[neighbour]==0) q.push(neighbour);
    }
  }
  if(cnt==n) return false;
  else return true;
}

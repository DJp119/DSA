/*
    Time complexity: O(V+E)
    Space complexity: O(V)
    
    Where V is the number of vertices and E is the number of edges.
*/
#include <bits/stdc++.h> 
void toposort(int node,vector<bool>&visited,stack<int>&s,unordered_map<int,list<int>>&adj){
    visited[node]=1;
    for(auto neighbour:adj[node]){
        if(!visited[neighbour]){
            toposort(neighbour, visited, s, adj);
        }
    }   
    
    s.push(node);
}
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    // create adj list
    unordered_map<int,list<int>>adj;
    for(int i=0;i<edges.size();i++){
        int u=edges[i][0];
        int v=edges[i][1];
        adj[u].push_back(v);
    }
    vector<bool>visited(v,0);
    stack<int> s;
    // call dfs toplofical sort util function for all components
    for(int i=0;i<v;i++){
        if(!visited[i]){
            toposort(i,visited,s,adj);
        }
    }
    vector<int>ans;
    while(!s.empty()){
        ans.push_back(s.top());
        s.pop();
    }
    return  ans;
}



Kahn’s Algorithm
/*
    Time complexity: O(V+E)
    Space complexity: O(V)
    
    Where V is the number of vertices and E is the number of edges.
*/
#include <bits/stdc++.h> 
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    // create adj list
    unordered_map<int,list<int>>adj;
    for(int i=0;i<e;i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
    }
    // find all indegree
    vector<int> indegree(v);
    for(auto i:adj){
        for(auto j:i.second){
            indegree[j]++;
        }
    }
    //  0 indegree push kardo
    queue<int> q;
    for(int i=0;i<v;i++){
        if(indegree[i]==0) q.push(i);
    }
    // do bfs
    vector<int>ans;
    while(!q.empty()){
        int front = q.front();
        q.pop();

        // ans store
        ans.push_back(front);
        // neighbour indegree update 
        for(auto neighbour : adj[front]){
            indegree[neighbour]--;
            if(indegree[neighbour]==0) q.push(neighbour);
        }
    }
    return ans;
}

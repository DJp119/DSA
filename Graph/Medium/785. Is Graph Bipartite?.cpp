BFS
Space = O(n) + O(n)
Time = O(n) * [O(n)+O(2E)]
class Solution {
private:
    bool check(int node,int n,vector<vector<int>>& adj,vector<int>&color){
        queue<int>q;
        q.push(node);
        color[node]=0;
        while(!q.empty()){
            int frontNode = q.front();
            q.pop();
            for(auto neighbour : adj[frontNode]){
                if(color[neighbour]==-1){
                    color[neighbour]=!color[frontNode];
                    q.push(neighbour);
                }
                else if(color[neighbour]==color[frontNode]) return false;
            }
        }
    return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>color(n,-1);
        for(int i=0;i<n;i++){
            if(color[i]==-1) {
                if(check(i,n,graph,color)==false) return false;
            }
        }
    return true;
    }
};

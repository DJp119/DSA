// DFS
class Solution
{
public:
    void ts(int start, vector<bool> &visited, stack<int> &s, vector<int> adj[])
    {
        visited[start] = 1;

        for (int nbr : adj[start])
        {
            if (!visited[nbr])
            {
                ts(nbr, visited, s, adj);
            }
        }
        s.push(start);
    }

    // Function to return a list containing vertices in Topological order.
    vector<int> topoSort(int V, vector<int> adj[])
    {
        vector<bool> visited(V);
        stack<int> s;

        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                ts(i, visited, s, adj);
            }
        }

        vector<int> res;
        while (!s.empty())
        {
            res.push_back(s.top());
            s.pop();
        }

        return res;
    }
};


// BFS
class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) {
	    vector<int> res;
	    vector<int> indegree(V, 0);
	    
	    for(int i = 0; i < V; i++) {
	        for(int nbr : adj[i]) {
	            indegree[nbr]++;
	        }
	    }
	    
	    queue<int> q;
	    for(int i = 0; i < V; i++) {
	        if(indegree[i] == 0) {
	            q.push(i);
	        }
	    }
	    
	    while(!q.empty()) {
	        int curr = q.front(); q.pop();
	        res.push_back(curr);
	        
	        for(int nbr : adj[curr]) {
	            indegree[nbr]--;
	            if(indegree[nbr] == 0) q.push(nbr);
	        }
	    }
	    
	    return res;
	}
};

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, list<int>> adj;
        for (int i = 0; i < prerequisites.size(); i++) {
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];
            adj[u].push_back(v);
        }
        // find the indegree
        int n = numCourses; 
        vector<int> indegree(n);
        for (auto i : adj) {
            for (auto j : i.second) indegree[j]++;
        }
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) q.push(i);
        }
        // BFS
        int count = 0;
        while (!q.empty()) {
            int front = q.front();
            q.pop();
            count++;

            for (auto neighbour : adj[front]) {
                indegree[neighbour]--;
                if (indegree[neighbour] == 0) q.push(neighbour);
            }
        }
        return count == numCourses;
    }
};

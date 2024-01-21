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


// DFS 
class Solution {
    bool checkDFS(int node, unordered_map<int, bool>& visited, unordered_map<int, bool>& dfsvisited, unordered_map<int, list<int>>& adj) {
        visited[node] = true;
        dfsvisited[node] = true;
        
        for (auto neighbour : adj[node]) {
            if (!visited[neighbour]) {
                bool cycleDet = checkDFS(neighbour, visited, dfsvisited, adj);
                if (cycleDet) return true;
            } else if (dfsvisited[neighbour]) {
                return true;  // If the neighbour is visited in the current DFS traversal, then it's a back edge, indicating a cycle
            }
        }
        
        dfsvisited[node] = false;  // Move this line inside the loop
        return false;
    }

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, list<int>> adj;
        for (int i = 0; i < prerequisites.size(); i++) {
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];
            adj[u].push_back(v);
        }

        unordered_map<int, bool> visited;
        unordered_map<int, bool> dfsvisited;
        int size = numCourses;
        int count = 0;

        for (int i = 0; i < size; i++) {
            if (!visited[i]) {
                bool cycleDet = checkDFS(i, visited, dfsvisited, adj);
                if (cycleDet) return false;  // If there is a cycle, it's impossible to finish all courses
            }
        }

        return true;  // If no cycle is detected, it's possible to finish all courses
    }
};

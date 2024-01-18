/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
    private:
    unordered_map<Node*,Node*>visited;
public:
    Node* cloneGraph(Node* node) {
        if(node==NULL) return node;
        if(visited[node]) return visited[node];
        Node* cloned = new Node(node->val);
        visited[node]=cloned;
        for(auto nei:node->neighbors){
            cloned->neighbors.push_back(cloneGraph(nei));
        }
        return cloned;
    }
};
class Solution{
    public:
    Node* dfs(Node* cur,unordered_map<Node*,Node*>&mp){
        vector<Node*> neighbor;
        Node* clone = new Node(cur->val);
        mp[cur]=clone;
        for(auto it:cur->neighbors){
            if(mp.find(it)!=mp.end())  neighbor.push_back(mp[it]);
            else neighbor.push_back(dfs(it,mp));
        }
        clone->neighbors=neighbor;
        return clone;
    }
    Node* cloneGraph(Node* node){
        unordered_map<Node*,Node*>mp;
        if(node==NULL) return NULL;
        if(node->neighbors.size()==0) {
            Node* clone = new Node(node->val);
            return clone;
        }
        return dfs(node,mp);
    }
};

//  BFS

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node) return NULL;

        unordered_map<Node*, Node*> copies;
        Node* copy = new Node(node -> val, {});
        copies[node] = copy;
        queue<Node*> todo;
        todo.push(node);
        while (!todo.empty()) {
            Node* cur = todo.front();
            todo.pop();
            for (Node* neighbor : cur -> neighbors) {
                if (copies.find(neighbor) == copies.end()) {
                    copies[neighbor] = new Node(neighbor -> val, {});
                    todo.push(neighbor);
                }
                copies[cur] -> neighbors.push_back(copies[neighbor]);
            }
        }
        return copy;
    }
};
// TC - O(E*V)
// SC - O(E*V + 2*V + V)

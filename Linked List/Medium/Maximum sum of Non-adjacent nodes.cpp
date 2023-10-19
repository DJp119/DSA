class Solution{
  public:
  pair<int,int> solve(Node* root){
      if(root==NULL) {
          pair<int,int> p= make_pair(0,0);
          return p;
      }
      pair<int,int>left = solve(root->left);
      pair<int,int>right = solve(root->right);
      
      pair<int,int> result;
      result.first= root->data+left.second+right.second;
      result.second = max(left.first,left.second) + max(right.first,right.second);
      return result;
  }
    //Function to return the maximum sum of non-adjacent nodes.
    int getMaxSum(Node *root) 
    {
        // Add your code here
        pair<int,int> ans = solve(root);
        return max(ans.first ,ans.second);
    }
};

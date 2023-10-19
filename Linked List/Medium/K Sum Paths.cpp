class Solution{
    void k_path(Node* root,int k,unordered_map<int,int> &p,int sum,int &count){
        if(root){
            if(sum + root->data == k) count++;
            count += p[sum+root->data-k];
            p[sum+root->data]++;
            k_path(root->left,k,p,sum+root->data,count);
            k_path(root->right,k,p,sum+root->data,count);
            p[sum+root->data]--;
        }
    }
  public:
    int sumK(Node *root,int k)
    {
        // code here
        int count = 0;
        unordered_map<int,int>p;
        k_path(root,k,p,0,count);
        
        return count;
    }
};

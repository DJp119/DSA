class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {

            int n = matrix.size();
            int m = matrix[0].size();
            for(int i = 0 ; i<n;i++){
                for(int j = 0 ; j<i;j++){
                    swap(matrix[i][j],matrix[j][i]);
                }
            }

            for(int i = 0 ; i<n;i++){
                reverse(matrix[i].begin(),matrix[i].end());
            }
    }
};



https://assets.leetcode.com/users/images/0ab215cd-9cd8-4872-90a7-901fb660dc67_1682068950.8864057.gif

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int col0 = 1 ;
        int n = matrix.size();
        int m = matrix[0].size();
        for(int i = 0;i<n;i++){
            for(int j = 0 ; j<m;j++){
                if(matrix[i][j]==0){
                    matrix[i][0]=0;
                    if(j != 0){
                        matrix[0][j]=0;
                    }
                    else{
                        col0 = 0;
                    }
                }
            }
        }
        for(int i = 1 ; i<n;i++){
            for(int j = 1;j<m;j++){
                if(matrix[i][0] == 0 || matrix[0][j]==0){
                    matrix[i][j]=0;
                }
            }
        }
        if(matrix[0][0]==0){
            for(int j = 0 ; j<m;j++){
                matrix[0][j]=0;
            }
        }
        if(col0 == 0){
            for(int i = 0 ; i<n;i++){
                matrix[i][0]=0;
            }
        }
    }
};



class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(); 
        int n = matrix[0].size(); 
        set<int> rows, cols;

        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(matrix[i][j] == 0) {
                    rows.insert(i);
                    cols.insert(j);
                }
            }
        }

        for(int row : rows)
            for(int j = 0; j < n; ++j)
                matrix[row][j] = 0;

        for(int col : cols)
            for(int i = 0; i < m; ++i)
                matrix[i][col] = 0;
    }
};

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool firstRowHasZero = false;
        bool firstColHasZero = false;
        int m = matrix.size();
        int n = matrix[0].size();

        // Check if the first row has a zero[^7^][7]
        for(int i = 0; i < n; i++) {
            if(matrix[0][i] == 0) {
                firstRowHasZero = true;
                break;
            }
        }

        // Check if the first column has a zero[^7^][7]
        for(int i = 0; i < m; i++) {
            if(matrix[i][0] == 0) {
                firstColHasZero = true;
                break;
            }
        }

        // Use first row and column as markers, set matrix[i][0] and matrix[0][j] to 0 if matrix[i][j] is 0[^16^][16]
        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                if(matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        // Zero out cells based on the markers in the first row and column[^23^][23]
        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                if(matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }

        // Zero out the first row if needed
        if(firstRowHasZero) {
            for(int i = 0; i < n; i++) matrix[0][i] = 0;
        }

        // Zero out the first column if needed
        if(firstColHasZero) {
            for(int i = 0; i < m; i++) matrix[i][0] = 0;
        }
    }
};

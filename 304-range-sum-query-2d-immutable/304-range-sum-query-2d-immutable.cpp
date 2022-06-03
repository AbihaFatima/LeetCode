//Time Complexity: O(1)
//Space Complexity: O(M*N)
class NumMatrix {
private:
    vector<vector<int>>mat;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int m=matrix.size(),n=matrix[0].size();
        mat = vector<vector<int>>(m+1,vector<int>(n+1,0));
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                //In every block, we store the sum of all the elements in the matrix from upper left corner to that point. i.e :
                mat[i][j] = matrix[i-1][j-1] + mat[i-1][j] + mat[i][j-1] - mat[i-1][j-1];
/*  Example:
             1  2  3                      1  3  6
             4  1  2           ->         5  8  13
             1  2  1                      6  11 17
*/
            }
        }
    }
    
    int sumRegion(int r1, int c1, int r2, int c2) {
        return mat[r2+1][c2+1] - mat[r1][c2+1] - mat[r2+1][c1] + mat[r1][c1]; 
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
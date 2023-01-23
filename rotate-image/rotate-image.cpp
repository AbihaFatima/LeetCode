class Solution {
public:
    //Optimised in-place solution
    //TC:O(N^2)
    //SC: O(1)
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        //Finding Transpose of the matrix
        for(int i=0;i<n;i++)
            for(int j=i;j<n;j++)
                swap(matrix[i][j],matrix[j][i]);
        
        //Swapping the columns by 2-pointer approach to get matrix rotated by 90 degrees
        for(int i=0;i<n;++i){
            int left=0, right=n-1;
            while(left<right){
                swap(matrix[i][left],matrix[i][right]);
                ++left;
                --right;
            }
        }
    }
    
};
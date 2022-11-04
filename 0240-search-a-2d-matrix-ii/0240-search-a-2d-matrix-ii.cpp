class Solution {
public:
    //TC: O(logN)
    //SC: O(1)
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row=0;
        int col=matrix[0].size()-1;
        while(row<matrix.size() && col>=0){
            if(target == matrix[row][col]){
                return true;
            }
            else if(target < matrix[row][col]){
                col--;
            }
            else
                row++;
        }
        return false;
    }
};
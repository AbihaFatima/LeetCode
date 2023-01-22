class Solution {
public:
    //tc-O(logN) sc-O(1)
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row=0, col=matrix[0].size()-1;
        while(row<matrix.size() and col>=0){
            if(matrix[row][col]==target) return true;
            else if(matrix[row][col]<target) row++;
            else col--;
        }
        return false;
    }
};
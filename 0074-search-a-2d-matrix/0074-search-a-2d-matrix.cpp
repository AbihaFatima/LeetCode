class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int low=0, high=matrix.size()-1;
        //searching in first col to get the target row
        while(low<=high){
            int mid = (low+high)/2;
            if(matrix[mid][0] > target) high=mid-1;
            else if(matrix[mid][0] < target) low=mid+1;
            else return true;
        };
        int row=high;
        if(row>=0){
            low=0, high=matrix[row].size() - 1;
            while(low<=high){
                int mid = (low+high)/2;
                if(matrix[row][mid] > target) high=mid-1;
                else if(matrix[row][mid] < target) low=mid+1;
                else return true;
            }
        }
        return false;
    }
};
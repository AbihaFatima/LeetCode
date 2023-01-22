class Solution {
public:
    //Time Complexity : O(log(m) + log(n)) = O(log(mn)
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
    if (matrix.size() == 0 || matrix[0].size() == 0) return false;
    int low=0;
    int high=matrix.size() - 1;
    //searching in first column
    while(low <= high){
        int middle=(low + high)/2;
        if (matrix[middle][0] < target) low=middle+1;
        else if (matrix[middle][0] > target) high=middle-1;
        else return true;
    }
    //We got the row to be searched i.e row=high
    int row = high;
    if (row >= 0){
        low =0;
        high=matrix[row].size() - 1;
        while (low <= high){
            int middle=(low + high)/2;
            if (matrix[row][middle] < target) low=middle+1;
            else if (matrix[row][middle] > target) high=middle-1;
            else return true;
        }
    }
    return false;
    }
};
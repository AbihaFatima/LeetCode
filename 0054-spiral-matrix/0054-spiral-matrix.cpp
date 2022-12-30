class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int>ans;
        int r=matrix.size(), c=matrix[0].size();
        int startRow = 0, endRow = r-1;
        int startCol = 0, endCol = c-1;
        
        while(startRow <= endRow && startCol<=endCol){
            //Traverse the startRow first
            for(int j=startCol;j<=endCol;j++){
                ans.push_back(matrix[startRow][j]);
            }   
            startRow++;
            //Now starting from EndCol
            for(int i=startRow; i<=endRow; i++){
                ans.push_back(matrix[i][endCol]);
            }
            endCol--;
            //Traversing EndRow
            if(endRow >= startRow){
                for(int j=endCol;j>=startCol;j--){
                    ans.push_back(matrix[endRow][j]);
                }
                endRow--;
            }
            //Traverse startCol
            if(startCol <= endCol){
                for(int i=endRow; i>= startRow; i--){
                    ans.push_back(matrix[i][startCol]);
                }
                startCol++;
            }
        }
        return ans;
    }
};
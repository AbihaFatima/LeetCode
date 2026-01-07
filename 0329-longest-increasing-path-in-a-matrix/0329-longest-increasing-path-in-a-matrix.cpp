/*
dp[i][j] stores the length of the longest increasing path starting from cell (i, j).
For each cell, run DFS and explore all 4 directions.
If dp[i][j] is already computed, return it to avoid recomputation.
Track the global maximum across all starting cells.
TC and SC: O(m*n)
*/
class Solution {
public:
    vector<pair<int,int>> dir={{1,0},{-1,0},{0,1},{0,-1}};
    int dfs(int i, int j, vector<vector<int>>& matrix, vector<vector<int>>& dp){
        //base case if the lenth from that cell to end is already computed return
        if(dp[i][j] > 0) return dp[i][j];

        int path_len = 1;
        //explaore its neighbours
        for(auto d: dir){
            int newX = i + d.first;
            int newY = j + d.second;
            //check if that cell is in bound and strictly incr.
            if(newX >= 0 && newX < matrix.size() && newY >=0 && newY < matrix[0].size() && matrix[newX][newY] > matrix[i][j]){
                path_len = max(path_len, 1 + dfs(newX,newY, matrix, dp));
            }
        }
        dp[i][j] = path_len;
        return path_len;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size(), m=matrix[0].size();
        vector<vector<int>> dp (n, vector<int>(m, 0));
        int max_len = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                max_len = max(max_len, dfs(i,j,matrix,dp));
            }
        }

        return max_len;
    }
};
class Solution {
public:
    //TC: O(M.N)
    //SC: O(M.N)
    int mod = 1000000007;
    int dfs(vector<vector<int>>& grid, int i, int j, vector<vector<int>>& dp, int parent) {
        // Check if current cell is out of bound or not increasing
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] <= parent) return 0; 
        if (dp[i][j] != -1) return dp[i][j];
        // Recursive calls for four directions (down, up, right, left)
        int down = dfs(grid, i + 1, j, dp, grid[i][j]);
        int up = dfs(grid, i - 1, j, dp, grid[i][j]);
        int right = dfs(grid, i, j + 1, dp, grid[i][j]);
        int left = dfs(grid, i, j - 1, dp, grid[i][j]);
        
        return dp[i][j] = (up+down+left+right+1) % mod;
    }
    int countPaths(vector<vector<int>>& grid) {
        vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size(), -1));
        for (int i = 0; i < grid.size(); i++)
            for (int j = 0; j < grid[0].size(); j++)
                if (dp[i][j] == -1) dfs(grid, i, j, dp, -1);
        
        long long ans = 0;
        for (int i = 0; i < grid.size(); i++)
            for (int j = 0; j < grid[0].size(); j++) 
                ans = (ans + dp[i][j]) % mod;
        return ans;
    }
};
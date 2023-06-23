class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int prev = -1, ans = 0, n = nums.size();
        vector<unordered_map<int,int>> dp(n);
        for(int i = 0; i<n; i++){
          for(int j = 0; j<i; j++){
            int diff = nums[i]-nums[j];
            if(dp[j].count(diff)) dp[i][diff] = 1 + dp[j][diff];
            else dp[i][diff]  = 2;
            ans = max(ans, dp[i][diff]);
          }
        }
        return ans;
    }
};
class Solution {
public:
    //Memoization:
    int robHelper(vector<int>& nums, int i, vector<int>& dp){
        if(i >= nums.size()) return 0;
        if(dp[i] != -1){
            return dp[i];
        }
        //case a: when robber robs ith house;
        int a = robHelper(nums,i+2,dp)+nums[i];
        //case b: when robber doesn't rob ith house;
        int b = robHelper(nums,i+1,dp);
        return dp[i] = max(a,b);
    }
    int rob(vector<int>& nums) {
        vector<int>dp(nums.size(),-1);
        return robHelper(nums,0,dp);
    }
    
//Tabulation
//Time Complexity : O(N)
//Space Complexity : O(N)
//     int rob(vector<int>& nums) {
//         int n = nums.size();
        
//         if(n==1){ //Base Case
//             return nums[0];
//         }
        
//         vector<int>dp(n);
        
//         dp[0] = nums[0];
//         dp[1] = max(nums[0],nums[1]);
        
//         for(int i=2;i<n;i++){
//             dp[i] = max(dp[i-1], dp[i-2]+nums[i]);
//         }
        
//         return dp[n-1];
//     }
};
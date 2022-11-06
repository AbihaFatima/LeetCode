class Solution {
public:
    //Extension to house robber-I, here the 1st and last houses are neighbouring as the list is circular 
    //so we will make 2 arrays one from 1st house to n-1th house and second from 2nd to nth house
    
    int robHelper(vector<int>& arr) {
        int n = arr.size();
        if(n==1){ 
            //Base Case
            return arr[0];
        }
        vector<int>dp(n);
        dp[0] = arr[0];
        dp[1] = max(arr[0],arr[1]);
        for(int i=2;i<n;i++){
            dp[i] = max(dp[i-1], dp[i-2]+arr[i]);
        }
        return dp[n-1];
    }
    
    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        if(nums.size() == 2) return max(nums[0],nums[1]);
        
        vector<int>dp1(nums.begin(),nums.end()-1);
        vector<int>dp2(nums.begin()+1,nums.end());
        
        return max(robHelper(dp1),robHelper(dp2));
    }
};
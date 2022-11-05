class Solution {
public:
    //Intuition: if sum of array elements is odd, equal sum partition cannot happen so return false
    //if even, call find subset sum exists or not on sum/2
    
    bool subsetSum(vector<int>&nums, int sum, int n){
        bool dp[n+1][sum+1];
        //Initialization
        for(int i=0;i<=n;i++){
            for(int j=0;j<=sum;j++){
                if(i==0) dp[i][j]=false;
                if(j==0) dp[i][j]=true;
            }
        }
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=sum;j++){
                if(nums[i-1] <= j){
                    //choose or reject
                    dp[i][j] = dp[i-1][j-nums[i-1]] || dp[i-1][j];
                }
                else{
                    //reject it
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[n][sum];
    }
    
    bool canPartition(vector<int>& nums){
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        if(sum%2 != 0){
            return false;
        }
        return subsetSum(nums,sum/2,n);
    }
};
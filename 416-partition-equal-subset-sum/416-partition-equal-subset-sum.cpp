class Solution {
public:
    bool subsetSum(vector<int>& nums, int sum, int &n){
        bool t[n+1][sum+1];
        //initialization
        for(int i=0;i<=n;i++){
            for(int j=0;j<=sum;j++){
                if(i==0) t[i][j]=false;
                if(j==0) t[i][j]=true;
            }
        }
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=sum;j++){
                if(nums[i-1] <= j){
                    t[i][j] = t[i-1][j-nums[i-1]] || t[i-1][j];
                }
                else
                    t[i][j] = t[i-1][j];
            }
        }
        return t[n][sum];
    }
    
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        bool ans;
        for(int i=0;i<n;i++){
            sum += nums[i];
        }
        
        if(sum%2 != 0) 
            return false;
        
        else if(sum%2 == 0) 
            ans = subsetSum(nums,sum/2,n);
        
        return ans;
    }
};
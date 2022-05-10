class Solution {
public:
    //DP (Tabulation Method)
    //This question is same as number of subsets with given difference 
    int countSubsetSum(vector<int>& nums, int sum){
        int n = nums.size();
        int t[n+1][sum+1];
        for(int i=0;i<=n;i++){
            for(int j=0;j<=sum;j++){
                if(i==0) t[i][j]=0;
                if(j==0) t[i][j]=1;
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=0;j<=sum;j++){
                if(nums[i-1] <= j){
                    t[i][j] = t[i-1][j-nums[i-1]] + t[i-1][j];
                }
                else
                    t[i][j] = t[i-1][j];
            }
        }
        return t[n][sum];
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
        target=abs(target);
        int nums_sum = 0;
        for(int i=0;i<nums.size();i++){
            nums_sum += nums[i];
        }
        int S=(target+nums_sum)/2;
        if(nums_sum<target || (target+nums_sum)%2 != 0) return 0;
        return countSubsetSum(nums,S);
    }
};
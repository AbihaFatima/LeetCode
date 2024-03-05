class Solution {
public:
    //Kadanes Algo - [tc: O(N)]
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        int ans = INT_MIN;
        int sum=0;
        for(int i=0;i<n;i++){
            sum += nums[i];
            ans = max(ans, sum);
            sum = sum < 0 ? 0 : sum; 
        }
        return ans;
    }
};
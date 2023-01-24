class Solution {
public:
    // Time Complexity : O(N)
    // Kadane's Algorithm
    int maxSubArray(vector<int>& nums){
        int maxSum = INT_MIN;
        int currSum = 0;
        for(int i=0;i<nums.size();i++){
            currSum += nums[i];
            maxSum=max(maxSum,currSum);
            if(currSum < 0){
                currSum = 0;
            }
        }
        return maxSum;
    }
};
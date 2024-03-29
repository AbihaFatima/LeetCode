class Solution {
public:
    //Brute-force approach  - O(N^2)
//     int maxSubArray(vector<int>& nums) {
//        int max_so_far = nums[0];
//        int curr_max = nums[0];

//        for (int i = 1; i < nums.size(); i++)
//        {
//             curr_max = max(nums[i], curr_max+nums[i]);
//             max_so_far = max(max_so_far, curr_max);
//        }
//        return max_so_far;
//     }
    
    //Optimised Approach:
    //Time Complexity : O(N)
    //Kadane's Algorithm
    // int maxSubArray(vector<int>& nums){
    //     int maxSum = INT_MIN;
    //     int currSum = 0;
    //     for(int i=0;i<nums.size();i++){
    //         currSum += nums[i];
    //         if(maxSum < currSum){
    //             maxSum = currSum;
    //         }
    //         if(currSum < 0){
    //             currSum = 0;
    //         }
    //     }
    //     return maxSum;
    // }
    
    int maxSubArray(vector<int>& nums){
        int currSum = 0, maxSum=INT_MIN;
        int i = 0, n = nums.size();
        while(i < n){
            currSum += nums[i];
            maxSum = max(currSum, maxSum);
            if(currSum < 0) currSum=0;
            i++;
        }
        return maxSum;
    }
};
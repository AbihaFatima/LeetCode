class Solution {
public:
    //Time Complexity: O(N) or O(maxSize) where maxSize=10001 acc. to constraints
    //Space Complexity: O(maxSize)
    int deleteAndEarn(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr(10001,0); //Creating a vector to map the nums element to their sum of freq
        vector<int> dp(10001,0);
        
        for(int i=0;i<n;i++){
			// arr stores the maximum sum we could generate if we select all the elements equal to nums[i]
			// if nums is [2, 2, 3, 3, 3, 4] then arr would be [0, 0, 4, 9, 4]
            arr[nums[i]] += nums[i];
        }
        
        dp[0] = arr[0];
        dp[1] = max(arr[0],arr[1]);
        
        for(int i=2;i<10001;i++){
            //Now applying house robber concept on arr, that is we can't rob two adjacent elements
            dp[i] = max(dp[i-1], dp[i-2]+arr[i]);
        }
        
        return dp[10000];
    }
};
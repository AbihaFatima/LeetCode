class Solution {
private: 
    int maxSize = 1e4+1;    //According to contraints
public:
    //Time Complexity: O(N) or O(maxSize)
    //Space Complexity: O(maxSize)
    int deleteAndEarn(vector<int>& nums) {
        int n = nums.size();
        vector<int> map_arr(maxSize); //Creating a vector to map the nums element to their sum of freq
        
        for(int i=0;i<n;i++){
            map_arr[nums[i]] += nums[i];
        }
        
        vector<int>dp(maxSize+1, 0);
        dp[1] = map_arr[0];
        dp[2] = max(map_arr[0],map_arr[1]);
        
        for(int i=3;i<=maxSize;i++){
            dp[i] = max(dp[i-1], dp[i-2]+map_arr[i-1]);
        }
        
        return dp[maxSize];
    }
};
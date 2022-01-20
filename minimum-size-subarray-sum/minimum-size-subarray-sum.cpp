class Solution {
public:
    //Two Pointer Approach
    //Time Complexity : O(N)
    //Space Complexity : O(1)
    int minSubArrayLen(int target, vector<int>& nums) {
        //Initialize left pointer to 0 and sum to 0
        int left = 0;
        int sum = 0;
        int n = nums.size();
        int ans = INT_MAX;
        for(int i=0;i<n;i++){ //Iterate over nums
            sum += nums[i];//add nums[i] to sum
            
            while(sum >= target){
                ans = min(ans, i+1-left); //where i+1-left is size of current subarray
                sum -= nums[left++]; //Subtract nums[left] from sum and increment left
            }
        }
        if(ans != INT_MAX) return ans;
        else return 0;
    }
};
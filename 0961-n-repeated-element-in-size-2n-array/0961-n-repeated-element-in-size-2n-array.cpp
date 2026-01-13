class Solution {
public:
//If one value appears n times in an array of size 2n, at least two occurrences being near each other. 
//TC: O(N) SC:O(1)

    int repeatedNTimes(vector<int>& nums) {
        int len = nums.size();
        for(int i = 0;i<len-1;i++) {
            if(nums[i] == nums[i+1]) return nums[i];
            if(i+2 < len && nums[i]==nums[i+2]) return nums[i];

            ////Why up to +3? Because with n repetitions, at least two copies must fall within distance ≤ 3.
            if(i+3 < len && nums[i]==nums[i+3]) return nums[i];
            
        }
        return -1;
    }
};
class Solution {
public:
    //Using Moore Voting Algorithm
    int majorityElement(vector<int>& nums) {
        
    int majority = 0;
    for (int count = 1, i = 1; i < nums.size(); i++) {
        nums[majority] == nums[i] ? count++ : count--;
        if (count == 0) {
            majority = i;
            count = 1;
        }
    }
        
    return nums[majority];
    }
};
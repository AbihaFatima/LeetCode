class Solution {
public:
    //Time Complexity O(n)
    void moveZeroes(vector<int>& nums) {
    int last = 0, current = 0;
    while(current < nums.size()) {
        if(nums[current] != 0) {
            swap(nums[last], nums[current]);
            last++;
        }
        current++;
        }
    }
};
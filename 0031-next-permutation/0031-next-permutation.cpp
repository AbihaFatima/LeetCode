class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int breakP = -1;
        for(int i=nums.size()-1;i>0;i--){
            if(nums[i]>nums[i-1]){
                breakP = i-1;
                break;
            }
        }
        if(breakP < 0){
            reverse(nums.begin(),nums.end());
            return;
        }
        for(int i=nums.size()-1;i>=0;i--){
            if(nums[i] > nums[breakP]){
                swap(nums[breakP],nums[i]);
                reverse(nums.begin()+breakP+1,nums.end());
                break;
            }
        }
    }
};
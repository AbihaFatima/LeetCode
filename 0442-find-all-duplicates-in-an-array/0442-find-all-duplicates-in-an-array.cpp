class Solution {
public:
    //Using constant space
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int>ans;
        for(int i=0;i<nums.size();i++){
            int index = abs(nums[i])-1;
            nums[index] = -nums[index];
            if(nums[index] > 0) ans.emplace_back(index+1);
        }
        return ans;
    }
};
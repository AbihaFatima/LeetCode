class Solution {
    void generateSubsets(vector<int>& nums, int currIdx, vector<int>& subsets, vector<vector<int>>& ans){
        if(currIdx >= nums.size()){
            ans.push_back(subsets);
            return;
        }
        //considering the current value
        int currVal = nums[currIdx];
        subsets.push_back(currVal);
        generateSubsets(nums, currIdx+1, subsets, ans);
        
        //Not considering the current value
        subsets.pop_back();
        generateSubsets(nums, currIdx+1, subsets, ans);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans; //powerset
        vector<int>subsets;
        generateSubsets(nums, 0, subsets, ans);
        return ans;
    }
};
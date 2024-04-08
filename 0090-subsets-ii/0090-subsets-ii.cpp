class Solution {
private:
    void generateSubsetsWithDup(int index, vector<int>& subsets, set<vector<int>>& ans, vector<int>& nums){
        if(index >= nums.size()){
            ans.insert(subsets);
            return;
        }
        subsets.push_back(nums[index]);
        generateSubsetsWithDup(index+1, subsets, ans, nums);
        
        subsets.pop_back();
        generateSubsetsWithDup(index+1, subsets, ans, nums);
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>> ans;
        vector<int>subsets;
        sort(nums.begin(),nums.end());
        generateSubsetsWithDup(0, subsets, ans, nums);
        vector<vector<int>> res{ans.begin(),ans.end()};
        return res;
    }
};
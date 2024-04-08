//Without using sets
class Solution {
private:
    void generateSubsetsWithDup(int index, vector<int>& subsets, vector<vector<int>>& ans, vector<int>& nums){
        ans.push_back(subsets);//storing all the initial answers
        for(int i=index; i<nums.size();i++){
            if(i>index and nums[i]==nums[i-1]) continue; //avoiding duplicates
            else{
                subsets.push_back(nums[i]);
                generateSubsetsWithDup(i+1, subsets, ans, nums);
                subsets.pop_back();
            }
        }
        return;
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int>subsets;
        sort(nums.begin(),nums.end());
        generateSubsetsWithDup(0, subsets, ans, nums);
        return ans;
    }
};
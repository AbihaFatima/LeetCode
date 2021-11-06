class Solution {
public:
    //Time complexity is O(n)
    void subSet(int i,vector<int>&nums, vector<int>&temp, vector<vector<int>>&ans){
        if(i==nums.size()){
            ans.push_back(temp);
        }
        else
        {
            subSet(i+1,nums,temp,ans);
            temp.push_back(nums[i]);
            subSet(i+1,nums,temp,ans);
            temp.pop_back(); //backtracking
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp;
        vector<vector<int>> ans;
        subSet(0, nums, temp, ans);
        return ans;
    }
};
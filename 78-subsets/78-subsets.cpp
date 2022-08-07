class Solution {
public:
    //Time complexity is O(n)
    void subSet(int i,vector<int>&nums, vector<int>&temp, vector<vector<int>>&ans){
        if(i==nums.size()){
            ans.push_back(temp);
        }
        else
        {
            //When we include that element in the subset
            temp.push_back(nums[i]);
            subSet(i+1,nums,temp,ans);
            
            //When we don't include that element in the subset 
            temp.pop_back(); //backtracking
            subSet(i+1,nums,temp,ans);
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
class Solution {
public:
    void permutation(vector<int>& nums, int i,vector<vector<int>>&ans){
        int n= nums.size();
        if(i==n){
            ans.push_back(nums);
        }
        
        else{
        for(int j=i; j<n;j++){
            swap(nums[i],nums[j]);
            permutation(nums,i+1,ans);
            swap(nums[i],nums[j]); //Backtracking
        }
    }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        permutation(nums, 0, ans);
        return ans;
    }
};
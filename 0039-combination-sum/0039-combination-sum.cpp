class Solution {
public:
    void combinations(vector<int> &candidates, vector<int>comb,int currIndex, int currSum ,int &target, vector<vector<int>>&ans){
        if(currSum > target){
            return; //Backtrack
        }
        if(target == currSum){
            ans.push_back(comb);
            return;
        }
        for(int i=currIndex; i<candidates.size(); i++){
            comb.push_back(candidates[i]);
            currSum += candidates[i];
            combinations(candidates, comb,i,currSum, target,ans);
            comb.pop_back();
            currSum -= candidates[i];
        }
    }
        
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>comb; 
        vector<vector<int>>ans;
        combinations(candidates, comb, 0, 0,target,ans);
        return ans;
    }
};
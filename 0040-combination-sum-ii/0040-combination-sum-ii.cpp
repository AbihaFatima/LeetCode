class Solution {
private:
    void generateCombinationSumDup(int index, int target, vector<int>& subsets, vector<vector<int>>& ans,vector<int>& candidates){
        if(target == 0){
            ans.push_back(subsets);
            return;
        }
        else{
            for(int i=index; i<candidates.size();i++){
                if(i>index and candidates[i]==candidates[i-1]) continue; //avoiding duplicates
                else if(candidates[index] <= target){
                    subsets.push_back(candidates[i]);
                    generateCombinationSumDup(i+1, target-candidates[i], subsets, ans, candidates);
                    subsets.pop_back();
                }
            }
        }
        return;
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int>subsets;
        sort(candidates.begin(), candidates.end());
        generateCombinationSumDup(0, target, subsets, ans, candidates);
        return ans;
    }
};
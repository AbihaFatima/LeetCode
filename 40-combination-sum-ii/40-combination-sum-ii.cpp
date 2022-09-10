class Solution {
public:
    vector<vector<int>> ans;
    
    void uniqueComb(vector<int>& candidates, int target, int index, int currSum, vector<int>temp){
        if(currSum > target) return;
        
        if(currSum == target){
            ans.push_back(temp);
            return;
        }
        
        for(int i=index;i<candidates.size();i++){
            if(i && candidates[i]==candidates[i-1] && i>index) continue;
            temp.push_back(candidates[i]);
            currSum += candidates[i];
            uniqueComb(candidates,target,i+1,currSum,temp);
            temp.pop_back();
            currSum -= candidates[i];
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target){
        vector<int>temp;
        sort(candidates.begin(),candidates.end());
        uniqueComb(candidates,target,0,0,temp);
        return ans;
    }
};
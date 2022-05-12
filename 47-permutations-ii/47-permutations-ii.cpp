class Solution {
public:
    //Backtracking using a unordered_set
    //The key insight here is that by iterating through unique numbers, we can avoid duplication. Practice Permutations problem first.
    //Extra space of set is being used here
    
    vector<vector<int>> output;
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        generatePermutation(nums,0);
        return output;
    }
    
    void generatePermutation(vector<int>& nums,int i){
        if(i == nums.size())
        {
            output.push_back(nums);
            return;
        }
        unordered_set<int>s;
        for(int j=i;j<nums.size();j++)
        {
            if(s.find(nums[j]) != s.end()) continue;
            s.insert(nums[j]);
            swap(nums[i],nums[j]);
            generatePermutation(nums,i+1);
            swap(nums[i],nums[j]);
        }
    }
};
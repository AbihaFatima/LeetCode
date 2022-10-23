class Solution {
public:
    //TC:O(N)
    //SC:O(N)
    vector<int> findErrorNums(vector<int>& nums) {
        unordered_map<int,int> mp;
        vector<int> ans;
        for(auto it:nums){
            mp[it]++;
        }
        for(auto it : mp){
          if(it.second == 2)
              ans.push_back(it.first);
        }
        for(int i=1;i<=nums.size();i++){
          if(mp[i]==0)
              ans.push_back(i);
        }   
        return ans;
    }
};
class Solution {
public:
    //using unordered map
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        unordered_map<int,int>mp;
        vector<int>ans;
        for(int i=1;i<=nums.size();i++){
            mp[i]=0;
        }
        for(auto it : nums){
            mp[it]++;
        }
        for(int i=1;i<=mp.size();i++){
            if(mp[i] == 0) ans.emplace_back(i);
        }
        return ans;
    }
};
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> m;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]+=1;
        }
        
        for(auto it = m.begin(); it!=m.end();it++){
            if((it->second >=2 ))
                return true;
        }
        
        return false;
    }
};
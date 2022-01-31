class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int> hm;
        for (int i = 0; i < nums.size(); i++){
            hm[nums[i]]++;
        }
        int SNo;
        for(auto it=hm.begin();it!=hm.end();it++) {
        if (it->second == 1) {
            SNo = it->first;
            }
        }
        return SNo;
    }
};
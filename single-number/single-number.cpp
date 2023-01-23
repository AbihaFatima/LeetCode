class Solution {
public:
    //Linear time but not using constant space
    // int singleNumber(vector<int>& nums) {
    //     unordered_map<int,int> hm;
    //     for (int i = 0; i < nums.size(); i++){
    //         hm[nums[i]]++;
    //     }
    //     int SNo;
    //     for(auto it=hm.begin();it!=hm.end();it++) {
    //     if (it->second == 1) {
    //         SNo = it->first;
    //         }
    //     }
    //     return SNo;
    // }
    
    //Linear time and constant space:
        int singleNumber(vector<int>& nums) {
            int ans=0;
            for(auto i:nums){
                ans ^= i;
            }
            return ans;
        }
};
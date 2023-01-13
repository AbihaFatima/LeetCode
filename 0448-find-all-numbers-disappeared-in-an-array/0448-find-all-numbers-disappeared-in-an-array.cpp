class Solution {
public:
    // //using unordered map
    // vector<int> findDisappearedNumbers(vector<int>& nums) {
    //     unordered_map<int,int>mp;
    //     vector<int>ans;
    //     for(int i=1;i<=nums.size();i++){
    //         mp[i]=0;
    //     }
    //     for(auto it : nums){
    //         mp[it]++;
    //     }
    //     for(int i=1;i<=mp.size();i++){
    //         if(mp[i] == 0) ans.emplace_back(i);
    //     }
    //     return ans;
    // }
    
    //Using Constant Space
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int>ans;
        for(int i=0;i<nums.size();i++){
            int index = abs(nums[i]);
            if(nums[index-1] > 0) nums[index-1] = -abs(nums[index-1]);
        }
        for(int i=0;i<nums.size();i++){
            if(nums[i] > 0) ans.emplace_back(i+1);
        }
        return ans;
    }
};
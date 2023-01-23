class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
//// Using Hash-maps tc:O(N) sc:O(N)
//         unordered_map<int, int> m;
//         for(int i=0;i<nums.size();i++){
//             m[nums[i]]+=1;
//         }
        
//         for(auto it = m.begin(); it!=m.end();it++){
//             if((it->second >=2 ))
//                 return true;
//         }
        
//         return false;
        
////    using sorting
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]==nums[i+1]) return true;
        }
        return false;
    }
};
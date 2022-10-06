class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ans;
        unordered_set<int>hashmap(nums1.begin(),nums1.end());
        for(int i=0;i<nums2.size();i++){
            if(hashmap.find(nums2[i]) != hashmap.end()){
                ans.push_back(nums2[i]);
                hashmap.erase(nums2[i]);
            }
        }
        return ans;
    }
};
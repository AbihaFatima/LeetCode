class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int>m;
        for(int i=0;i<nums.size();i++)
        {
            if(!m.count(nums[i])) // if element is not present in m
                m[nums[i]] = i;
            else  {
                if(abs(m[nums[i]]-i)<=k) // if the diff is at most k
                    return true;
                else
                    m[nums[i]] =i;  
                }
        }
        return false;
    }
};
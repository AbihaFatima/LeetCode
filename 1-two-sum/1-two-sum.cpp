class Solution {
public:
    //Optimised Solution O(n)
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hash;
        vector<int> result;
            for(int i = 0; i < nums.size(); i++)
            {
                if (hash.count(target - nums[i])) // If the pair of this value to reach the target sum has been saved already
                {
                    result.push_back(hash[target - nums[i]]); // Get index of other value
                    result.push_back(i);
                    return result;
                }
                else // Pair has not yet been found, so save the value to hash table
                    hash[nums[i]] = i;
            }
        return result;
    }
};
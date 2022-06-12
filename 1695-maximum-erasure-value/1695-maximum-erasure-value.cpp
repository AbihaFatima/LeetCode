class Solution {
public:
    //Sliding Window Approach
    //Time Complexity: O(N)
    //Space Complexity: O(N) because of unordered_set
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_set<int>set;
        int i=0,j=0,currSum=0,ans=0;
        for(i=0,j=0;j<nums.size();j++){
            //If the element nums[j] is already present in the set
            while(set.find(nums[j])!=set.end()){
                set.erase(nums[i]);
                currSum -= nums[i];//Subtract that element from currSum
                i++;//Increase the ith index (Shrinking the window from start)
            }
            //else if element is not present so add it to the set
            set.insert(nums[j]);
            currSum+=nums[j]; //Update currSum
            ans = max(ans,currSum);
        }
        return ans;
    }
};
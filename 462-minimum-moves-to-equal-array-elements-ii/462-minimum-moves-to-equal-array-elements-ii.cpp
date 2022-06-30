class Solution {
public:
    /*
    Time Complexity: O(NlogN) + O(N) = O(NlogN)
    Space Complexity: O(1)
    Approach:  we just find the median after sorting the array which is nums[n/2] and add the absolute difference of the elements in the array with the median.
    */
    int minMoves2(vector<int>& nums) {
        int median, minSteps=0;
        int n = nums.size();
        sort(nums.begin(),nums.end());
        median = nums[n/2];
        for(int i=0;i<n;i++){
            minSteps += abs(nums[i]-median);
        }
        return minSteps;
    }
};
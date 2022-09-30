class Solution {
public:
    /* Approach : this can be done with a single binary search method as well. Let’s discuss that ->Instead of checking the mid with target (as done in a generic binary search), we check the mid with start and end -> cause the array is distorted -> so first we want to condition on that. Let’s say the nums[start] is less than the nums[mid] -> we get our new start and end -> the start and
mid.
So we just add one more condition to the already existing binary search conditions. We shift the start and end pointers after we’ve discovered the subarray where we need to shift. TimeComplexity O(N)
Here’s the full code:

    */
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int high=n-1, low=0;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(nums[mid] == target) return mid;
            if(nums[low] <= nums[mid]){
                if(target >= nums[low] && target<=nums[mid]) high=mid-1;
                else low = mid+1;
            }
            if(nums[mid] <= nums[high]){
                if(target >= nums[mid] && target <= nums[high]) low = mid+1;
                else high = mid-1;
            }
        }
        return -1;
    }
};
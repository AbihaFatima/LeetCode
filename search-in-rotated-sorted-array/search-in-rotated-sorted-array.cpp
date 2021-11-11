class Solution {
public:
    /* Approach : this can be done with a single binary search method as well. 
    Let’s discuss that ->Instead of checking the mid with target (as done in a generic binary search), 
    we check the mid with start and end -> cause the array is distorted -> so first we want to condition on that. 
    Let’s say the nums[start] is less than the nums[mid] -> we get our new start and end -> the start and mid.
So we just add one more condition to the already existing binary search conditions. 
We shift the start and end pointers after we’ve discovered the subarray where we need to shift. TimeComplexity O(N)
Here’s the full code:
    */
    int search(vector<int>& nums, int target) {
        
        int n = nums.size();
        int start = 0, end = n-1;
        int mid;
        while(start<=end){
            int mid = start + (end-start)/2;
            if(target == nums[mid]){
                return mid;
            }
            
            if(nums[start] <= nums[mid]){
                if(target >= nums[start] && target <= nums[mid]){
                    end = mid -1;
                }
                else
                    start = mid + 1;
            }
            
            if(nums[mid] <= nums[end]){
                if(target >= nums[mid] && target <= nums[end]){
                    start = mid + 1;
                }
                else
                    end = mid -1;
            }
            
        }
        return -1;
         
    }
};

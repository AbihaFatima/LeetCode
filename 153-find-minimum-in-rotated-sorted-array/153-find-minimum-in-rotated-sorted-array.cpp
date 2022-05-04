class Solution {
public:
    //Brute-force approach would be to use sorting function - TC:O(nlog(n)) SC: O(1)
    
    //Most Optimised Approach Using Binary Search - TC: O(log n)  SC: O(1)
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int low=0, high=n-1,mid;
    
        if(n==1){ //base case: to avoid TLE
            return nums[0];
        }
        
        
        while(low<high){
            mid = low + (high-low)/2;
            if(nums[low]<nums[high]){ // got a part that is not rotated
                return nums[low];
            }
            else if(nums[mid]>nums[high]){ 
                //mid is larger than right - min is in right side
                low = mid + 1;
            }
            else {
                // mid is smaller than right - min is in left side (including mid)
                high = mid;
            }
        }
        return nums[low];
    }
};
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int ele;
        int low=0, high=nums.size()-1;
        while(low<high){
            int mid = (low+high)/2;
            
            //If mid index is even subarray would be from 0 to mid which will be odd
            //single element can be in [0, mid] or [mid+1, n-1].
            if(mid%2 == 0){
                if(nums[mid] != nums[mid+1]) high=mid;
                else low=mid+1;
            }
            //Else if mid index is odd, subarray would be from 0 to mid will be even
            //single element can be 
            else{
                //Subarray [0, mid] length is even and if all elements in subarray appears twice 
                //means no single element, so if nums[mid] and nums[mid-1] are diff, single ele appears on left
                if(nums[mid] != nums[mid-1]) high=mid;
                else low=mid+1;
            }
        }
        return nums[low];
    }
};
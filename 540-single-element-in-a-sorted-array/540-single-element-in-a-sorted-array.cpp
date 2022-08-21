class Solution {
public:
    //Binary Search Approach
    //Time Complexity: O(logN)
    //Space Complexity: O(1)
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int mid, left=0, right=n-1;
        while(left < right){
            mid = left + (right-left)/2;
            if(mid % 2 == 0){
                if(nums[mid] != nums[mid+1]){
                    right = mid;
                }
                else{
                    left = mid + 1;
                }
            }
            else{
                if(nums[mid] != nums[mid-1]){
                    right = mid;
                }
                else{
                    left = mid + 1;
                }
            }
        }
        return nums[left];
    }
};
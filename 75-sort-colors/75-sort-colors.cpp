class Solution {
public:
    //Brute-force approach: using sort function so TC:O(nlogn) & SC:O(1)
    //Better-approach: count 0,1,2 and then display 0s first then 1 and then 2. TC:O(2N) & SC:O(1)
    //Most Optimal approach: using 3 pointers:
    void sortColors(vector<int>& nums) {
        int low = 0;
        int mid = 0;
        int high = nums.size()-1;
        while(mid<=high){
            if(nums[mid]==0){
                swap(nums[mid],nums[low]);
                mid++;
                low++;
            }
            else if(nums[mid]==1){
                mid++;
            }
            else{//when nums[mid]==2
                swap(nums[mid],nums[high]);
                high--;
            }
        }
    }
};
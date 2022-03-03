class Solution {
public:
    //Time Complexity : O(N)
    //Space Complexity : O(1)
    int numberOfArithmeticSlices(vector<int>& nums) {
        if(nums.size() < 3){
            return 0;
        }
        
        int previous_diff = nums[1]-nums[0];
        int curr_diff = 0, count=0, s=0;
        
        for(int i=1 ; i<nums.size()-1 ; i++){
            
            //Calculating the current difference
            curr_diff = nums[i+1] - nums[i];
            
            //Comparing current difference with previous difference
            if(curr_diff == previous_diff){
                count++;
            }
            
            // update prev diff with curr diff
            // as we didn't find consecutive elements with same difference
            else{
                previous_diff = curr_diff;
                count = 0;
            }
            s += count; // add current continuous arithmetic sequence count to ans
        }
        return s;
    }
};
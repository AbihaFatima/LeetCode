class Solution {
public:
    /*
    Time Complexity: O(N)
    Space Complexity: O(1)
    */
    bool checkPossibility(vector<int>& nums) {
        int count = 0;
        for(int i=1;i<=nums.size()-1;i++){
            
            //Non-decreasing sequence found
            if(nums[i]<nums[i-1]){
                //Incrementing the count and checking
                if(++count>1) return false;
                
                //in case of the 2nd element as i[1] < i[0] so make i[0] = i[1]
                //if prev of prev element of curr is less than or equal to it then only the we can make it non decreasing by making the greater equal to lesser (prev = curr).
                if(i==1 || nums[i-2] <= nums[i])
                    nums[i-1] = nums[i];
                
                //if prev of prev is greater than curr then we have to make the lesser equal to greater (curr = prev)
                else
                    nums[i] = nums[i-1];
            }
        }
        //this command will only run if the loop is totally traversed and count <= 1 so return true.
        return true;
    }
};
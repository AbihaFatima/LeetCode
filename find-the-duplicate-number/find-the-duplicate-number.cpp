class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        /*This Question can solved using sorting/Binary Seach approach but it will take O(N logN) time, so the most optimised approach would be to use 2-pointer approach
        So below is 2-pointer approach taking O(N) Time and O(1) space :)
        */
        int slow = nums[0];
        int fast = nums[0];
        
        do{
            slow = nums[slow];//moving slow one unit ahead
            fast = nums[nums[fast]]; //moving fast 2 units ahead
        }while(slow!=fast);
        
        //Now after the execution of above loop the fast and slow pointers will be colliding at some point
        //Now moving the slow pointer back to first pointer and then moving both pointers one by one
        slow = nums[0];

        while(slow!=fast){ //
            slow = nums[slow];
            fast = nums[fast];
        }
        //The point now where slow and fast collide is the duplicate number
        return slow;
    }
};
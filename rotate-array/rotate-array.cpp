class Solution {
public:
    /*
    First Approach(brute force approach) - TimeComplexity O(n^2) SpaceComplexity O(1)
                    Nested Loop each element shift
    Second Approach(TC and SC trade-off) - TC-O(N) SC-O(2N) ~ O(N)
                    Auxilary array for storing final rotated array
    */
    //Most Optimised Approach TimeComplexity - O(N) && SpaceComplexity-O(1)
    /*
    2-Pinter Approach
    In this Approach we are first rotating rightmost k elements and then rotatating all elements except right most k elements and finally rotating all the elements of the array.
    */
    
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        if(n==1) return; //Base Case
        
        k = k%n; //For handling the given constraint (example if value of k is 10^5 and n is 10^3 so to make k equivalent to vector length
        
        rotate_aux(nums, n-1-k+1, n-1); //Rotataing k right most elements
        rotate_aux(nums, 0 ,n-1-k); //Rotating all elements before k right most elements
        rotate_aux(nums, 0, n-1); //Rotating all the elements of the array
    }
    void rotate_aux(vector<int>&nums, int start, int end){
        int i=start, j=end;
        while(i<=j){
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
            i++;
            j--;
        }
    }
};
/*
PS: 4 lines of code using reverse function\U0001f604\U0001f601 :
 void rotate(vector<int>& nums, int k) {
        k %=nums.size();
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin()+k);
        reverse(nums.begin()+k, nums.end());
    }
*/
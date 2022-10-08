class Solution {
public:
    //Time Complexity : O(n^2)
    //Space Complexity : O(1)
    /*
    1. Sort the array nums, ans := 0, diff := Infinity, n := size of nums
    2. for i in range 0 to n – 1
        3. left := i + 1, right := n – 1
        4. while left < right
            5. temp := nums[left] + nums[right] + nums[i]
            6. If |target – temp| < diff, then ans := temp and diff := |target – temp|
            7. If temp = target, then return temp,
            8. Otherwise when temp > target, then decrease right by 1, else increase left by 1
9. return ans
    */
    
    int threeSumClosest(vector<int>& nums, int target) {
        
        sort(nums.begin(), nums.end());
        int ans = 0;
        int diff = INT_MAX ;
        int n = nums.size() ;
        for(int i = 0; i < n; i++)
        {
            int left = i + 1;
            int right = n - 1;
            while(left < right)
            {
                int temp = nums[left] + nums[right] + nums[i];
                if(abs(target - temp) < diff)
                {
                   ans = temp;
                   diff = abs(target - temp);
                }
                if(temp == target) return temp;
                else if(temp > target) right--;
                else left++;
            }
        }
      return ans;
    }
};
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int answer = nums.size();

        for(int i = 0; i < nums.size(); i++)
          answer ^= i ^nums[i];

        return answer;
    }
};
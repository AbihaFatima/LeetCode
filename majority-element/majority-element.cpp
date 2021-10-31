class Solution {
public:
    //Time complexity is O(n)
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> m;
        
        //For incrementing the frequency of each element
        for(auto a:nums){
            m[a]++;
            if(m[a]>nums.size()/2)
                return a;
        }
        return -1;
    }
//     //Using Moore Voting Algorithm
//     int majorityElement(vector<int>& nums) {
        
//     int majority = 0;
//     for (int count = 1, i = 1; i < nums.size(); i++) {
//         nums[majority] == nums[i] ? count++ : count--;
//         if (count == 0) {
//             majority = i;
//             count = 1;
//         }
//     }
        
//     return nums[majority];
//     }
};
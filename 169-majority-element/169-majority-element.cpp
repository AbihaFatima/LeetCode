class Solution {
public:
//     //Time complexity is O(n)
     //(time O(n) and space O(n))
//     int majorityElement(vector<int>& nums) {
//         unordered_map<int,int> m;
        
//         //For incrementing the frequency of each element
//         for(auto a:nums){
//             m[a]++;
//             if(m[a]>nums.size()/2)
//                 return a;
//         }
//         return -1;
//     }
    
    //Better approach is to sort the array/vector;
    //As the majority element will always lie in middle(sliding window) as in the question the majority element is going to be greater than n/2 so it is going to cover middle
    //So the time complexity of this approach is nlogn due to sorting and space complexity is O(1)
    
    //but extra space is not used here constrasting to last appraoch which used maps(time O(n) and space O(n))
    
//     int majorityElement(vector<int>& nums) {
//         int n = nums.size();
//         sort(nums.begin(),nums.end());
//         int majorityElement = nums[n/2];
//         int frequency=0;
        
//         for(auto a:nums){
//             if(a==majorityElement)
//                 frequency++;
//         }
//             if(frequency>n/2)
//                 return majorityElement;
//             else
//                 return -1;       
//     }
    
    
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

    //Same Algorithm (ie Moores Voting Algorithm can also be coded as):
     int majorityElement(vector<int>& nums) {
         int n=nums.size();
         int candidate = nums[0];
         int votes = 0, f=0;
         
         for(int i=0;i<n;i++){
             if(nums[i]==candidate){
                 votes++;
             }
             else{
                 votes--;
             }
             if(votes==0){
               candidate = nums[i];  
                 votes=1;
             }
         }
         for(int i=0;i<n;i++){
             if(nums[i]==candidate)
                 f++;
         }
         if(f>n/2)
             return candidate;
         
         return -1;
     }
    
    
};
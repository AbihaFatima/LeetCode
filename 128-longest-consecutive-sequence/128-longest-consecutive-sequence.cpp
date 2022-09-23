class Solution {
public:
    // //Very Very Brute-force approach O(n^3)
    // /*
    //     the overall complexity for this is O(N^2)
    // */
    // bool findNumber(vector<int>nums,int number){
    //     for(int a: nums){
    //         if(a==number)
    //             return true;
    //     }
    //     return false;
    // }
    // int longestConsecutive(vector<int>& nums) {
    //     int n= nums.size();
    //     int ans=0;
    //     for(int i=0;i<n;i++){
    //         int start = nums[i];
    //         while(findNumber(nums,start)){
    //             start++;
    //         }
    //         ans = max(ans,start-nums[i]);
    //     }
    //     return ans;
    // }
    
    /*
    Next better approach will be using STL sort
        that is the overall time complexity for this approach would be O(n log n) 
        {/*O(n log n) for using STL sort + O(n) for traversing through elements n times ~ O(n logn)
    
    that is we will sort the array then maintain a pointer (sequenceLen) if the previous element before the current element is 1 less than the current element and the sequenceLen would be incremented by one. else it would be assigned the value 1.
    */
    
     // int longestConsecutive(vector<int>& nums) {
     //     int sequenceLen = 1;
     //     int maxLen = 1;
     //    sort(nums.begin(),nums.end());    
     //     for(int i=1; i<nums.size(); i++){
     //         if(nums[i]==nums[i-1]+1){
     //             sequenceLen++;
     //         }
     //         else if(nums[i]==nums[i-1]){
     //             continue;
     //         }
     //         else{
     //             sequenceLen=1;
     //         }
     //         maxLen = max(maxLen, sequenceLen);      
     //     }
     //     return maxLen;
     // }
    
    
/*
    Now the next approach is most optimised approach is using unoredered_set; time complexity of this approach is O(N)
    //only unique values can be stored
    
    
*/
    
      int longestConsecutive(vector<int>& nums) {
          unordered_set<int> box;
          //insert elements in the set
          int ans=0;
          for(int i=0;i<nums.size();i++)
          {
              box.insert(nums[i]);
          }
          
          
          for(int i=0;i<nums.size();i++){ // O(N)
              int start = nums[i];
              
              if(box.find(start-1)!=box.end()){ //For avoiding repetetion in search
                  continue;
              }                  
                 while(box.find(start) != box.end()) //O(1)
              {
                  start++;
              }
            ans = max(ans, start-nums[i]);
          }

          return ans;
        
     }
    
};
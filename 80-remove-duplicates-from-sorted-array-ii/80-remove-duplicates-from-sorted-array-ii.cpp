class Solution {
public:
    //Hashmap approach
    //Time Complexity: O(N)
    //Space Complexity: O(N)
//     int removeDuplicates(vector<int>& nums) {
//         unordered_map<int,int>mp;
        
//         for(int i=0;i<nums.size();i++){
//             mp[nums[i]]++;
//             if(mp[nums[i]]>2){
//                nums.erase(nums.begin()+i); //Erase ith element
//             }
//         }
//         return nums.size();
//     }
    
    //Two Pointer Approach-Most optimised:
    //Time Complexity: O(N)
    //Space Complexity: O(1)
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()<3){
            return nums.size();
        }
        int index=2;
        for(int i=2;i<nums.size();i++){
            if(nums[i] != nums[index-2]){
                nums[index]=nums[i];
                index++;
            }
        }
        return index;
    }
    
};
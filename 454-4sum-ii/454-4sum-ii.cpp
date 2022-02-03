class Solution {
public:
    //Time Complexity: O(N^2)
    //Space Complexity: O(N^2)
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int count=0;
        map<int,int> mp;
        for(int k : nums3){
            for(int l : nums4){
                mp[k+l]++;
            }
        }
        for(int i : nums1){
            for(int j : nums2){
                if(mp.count(0-i-j)) //if -i-j exists in the map or not
                {
                    count += mp[0-i-j];
                }
            }
        }
        return count;
    }
};
class Solution {
public:
    /*
    Time Complexity: O(N^2)
    Space Complexity: O(N)
    Although it can be reduced to O(NlogN) using binary search/binary indexed tree
    Right now, came up with only brute-force solution
    */
    
    //Comparator Function
    //Sort the array in decreasing order of their heights and it the height of two persons is same then sort it in increasing order of their indices
    static bool compare(vector<int>&a, vector<int>&b){
        if(a[0]==b[0])
            return a[1]<b[1];
        
        return a[0]>b[0];
    }
    
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        vector<vector<int>> ans;
        
        sort(people.begin(),people.end(),compare);
        
        for(int i=0;i<people.size();i++){
            int index = people[i][1];
            ans.insert(ans.begin()+index, people[i]);
        }
        return ans;
    }
};
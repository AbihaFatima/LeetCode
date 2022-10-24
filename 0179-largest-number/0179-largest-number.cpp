class Solution {
public:
    //TC: O(NlogN)
    //SC: O(N)
    static bool cmp(string a, string b){
        return (a+b) > (b+a);
    }
    string largestNumber(vector<int>& nums) {
        vector<string>arr;
        //pushing all the numbers as string in arr
        for(auto it : nums){
            arr.push_back(to_string(it));
        }
        //Sort the arr in decreasing order
        sort(arr.begin(),arr.end(), cmp);
        string ans = "";
        for(auto it : arr){
            ans += it;
        }
        if(arr[0] == "0") 
            return "0";
        
        return ans;
    }
};
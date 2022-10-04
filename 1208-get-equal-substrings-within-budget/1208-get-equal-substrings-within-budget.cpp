class Solution {
public:
    //TC:O(N)
    //SC:O(N)
    int equalSubstring(string s, string t, int maxCost) {
        int n=s.length();
        vector<int>arr(n);
        for(int i=0;i<n;i++){
            arr[i] = abs(s[i]-t[i]);
        }
        int maxLen=INT_MIN, sum=0, start=0;
        for(int end=0;end<n;end++){
            sum += arr[end];
            while(sum>maxCost){
                sum -= arr[start];
                start++;
            }
            maxLen = max(maxLen, end-start+1);
        }
        return maxLen;
    }
};
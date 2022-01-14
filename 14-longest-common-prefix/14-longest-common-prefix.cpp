class Solution {
public:
    int mismatch(string s1, string s2, int n, int m){
        int size = min(n,m);
        int length =0;
        for(int i=0;i<size;i++){
            if(s1[i] == s2[i]){
                length++;
            }
            else
                break;
        }
        return length;
    }
    string longestCommonPrefix(vector<string>& strs) {
        string res = strs[0];
        int length = res.length();
        int n = strs.size();
        
        for(int i=1;i<n && length>0;i++){
            length =  mismatch(res, strs[i], length, strs[i].length());
        }
        
        return res.substr(0,length);
    }
};
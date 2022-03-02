class Solution {
public:

    bool isSubsequence(string s, string t) {
        if(s.size()>t.size()){
            return false;
        }
        int j=0, n=s.length(), k=t.length(); 
        for(int i=0 ; i<k && j<n ; i++){
            if(s[j]==t[i]){
                j++;
            }
        }
        if(j==n)
            return true;
        else
            return false;
    }
};
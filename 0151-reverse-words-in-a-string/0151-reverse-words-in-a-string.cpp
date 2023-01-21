class Solution {
public:
    string reverseWords(string s) {
        int n=s.length();
        int i=0;
        string res;
        while(i<n){
            while(i<n and s[i]==' ') i++;
            if(i>=n) break;
            int j=i+1;
            while(j<n and s[j]!=' ') j++;
            string temp = s.substr(i,j-i);
            if(res.length()==0) res=temp;
            else res=temp+" "+res;
            i=j+1;
        }
        return res;
    }
};
class Solution {
public:
    int lengthOfLastWord(string s) {
        //Both approaches are correct
        // int len=0, end= s.size()-1;
        // while(end>=0 && s[end]==' ') 
        //     end--;
        // while(end>=0 && s[end]!=' ')
        // {
        //     len++;
        //     end--;
        // }
        // return len;
        
        int res=0;
        for(int i=s.size()-1;i>=0;i--){
            if(s[i] == ' ' && res>0) return res;
            if(s[i]!= ' ') res++;
        }
        return res;
    }
};
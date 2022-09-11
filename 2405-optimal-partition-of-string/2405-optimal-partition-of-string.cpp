class Solution {
public:
    int partitionString(string s) {
        set<char>st;
        int count=0;
        for(int i=0;i<s.length();i++){
            if(st.find(s[i]) == st.end()){
                st.insert(s[i]);
            }
            else{
                count++;
                st.clear();
                st.insert(s[i]);
            }
        }
        
        if(!st.empty()) count++;
        
        return count;
    }
};
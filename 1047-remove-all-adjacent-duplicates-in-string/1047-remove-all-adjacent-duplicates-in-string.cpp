class Solution {
public:
    string removeDuplicates(string s) {
        int n = s.length();
        stack<char>st;
        for(int i=0;i<n;i++){
            if(st.empty() || st.top()!=s[i]){
                st.push(s[i]);
            }
            else{
                st.pop();
            }
        }
        string ans="";
        if(!st.empty()){
            while(!st.empty()){
                ans = st.top() + ans;
                st.pop();
            }
        }
        return ans;
    }
};
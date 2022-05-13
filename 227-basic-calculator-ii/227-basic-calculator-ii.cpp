class Solution {
public:
    int calculate(string s) {
        s += '+';
        int length = s.size();
        if(length == 0){
            return 0;
        }
        stack<int>st;
        long long int ans=0,curr=0;
        char sign='+';
        for(int i=0;i<s.size();i++){
            if(isdigit(s[i]))
                curr = (curr*10)+(s[i]-'0'); //keep forming the number, until you encounter an operator
            if(s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/'){
                if(sign=='+'){
                    st.push(curr);
                }
                else if(sign=='-'){
                    st.push((curr*-1));
                }
                else if(sign=='*'){
                    int t=st.top();
                    st.pop();
                    st.push(t*curr);
                }
                else if(sign=='/'){
                    int t=st.top();
                    st.pop();
                    st.push(t/curr);
                }
                curr = 0; 
                sign = s[i]; 
            }
        }        
    
    while (!st.empty()) {
            int t = st.top();
            ans += t; 
            st.pop();
    }
    
    return ans;  
   }
};
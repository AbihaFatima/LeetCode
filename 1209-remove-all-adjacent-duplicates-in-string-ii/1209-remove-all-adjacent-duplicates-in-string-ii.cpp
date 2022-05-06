class Solution {
public:
    //One of the optimal approach would be using Stacks
    //TC: O(N) because each element will be pushed and popped from the stack only once.
    //SC: O(N) making auxilary space for stack so O(N), result vector is the answer vector so its space will not be considered
    string removeDuplicates(string s, int k) {
        int n = s.size();
        if(n<k) return s; //Base-case
        
        //Using hint-2 : To make it more efficient, use a pair to store the value and the count of each character.
        stack<pair<char,int>> st;
        
        for(int i=0; i<n; ++i){
            if(st.empty() || st.top().first != s[i]) st.push({s[i],1});//Adding the first instance of the character
            else{ 
                auto prev = st.top();
                st.pop();
                st.push({s[i], prev.second+1});//incrementing the count of the character
            }
            if(st.top().second==k) st.pop(); //Popping the character if the count becomes equal to k
        }
        string res = "";
        while(!st.empty()){
            auto cur = st.top();
            st.pop();
            while(cur.second--){ //Pushing the remaining element to res vector and decrementing its frequency
                res.push_back(cur.first);
            }
        }
        reverse(res.begin(), res.end()); //As stack pops last element first so reversing it to get the final string
        return res;
    }
};
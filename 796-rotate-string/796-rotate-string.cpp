class Solution {
public:
    //Brute-force solution using 2 queues 
    bool rotateString(string s, string goal) {
        if(s==goal) return true;
        if(s.length() != goal.length()) return false;
        queue<char>q1,q2;
        for(int i=0;i<s.length();i++){
            q1.push(s[i]);
            q2.push(goal[i]);
        }
        int i=0;
        while(i<s.length()){
            char ft = q1.front();
            q1.push(ft);
            q1.pop();
            if(q1==q2) return true;
            i++;
        }
        return false;
    }
};
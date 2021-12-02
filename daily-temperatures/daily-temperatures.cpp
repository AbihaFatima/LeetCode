class Solution {
public:
    //The Brute-force approach would take O(N^2) time
    
/*
    Better Solution using stacks (space and time trade-off)
    Time complexity O(N)
    Space complexity O(N)
    vector<int> dailyTemperatures(vector<int>& temp) {
        stack<int> s;
        vector<int> res;
        int n = temp.size() - 1;
        
        for(int i=n;i>=0;i--){
            
            if(s.empty()){
                s.push(i);
                res.push_back(0);
            }
            else{
                while(!s.empty() && temp[s.top()]<=temp[i]){
                    s.pop();//we will keep doing this unless we have all smaller element at the top
                }
                 if(s.empty()){
                        s.push(i);
                        res.push_back(0);
                }
                else{
                    res.push_back(s.top()-i);
                    s.push(i);
                }
            }
        }
        reverse(res.begin(),res.end());
        return res;
    }
*/
    
    
    //most optimised solution (2-POINTER APPROACH \U0001f64c)
    //Time complexity : O(N)
    //Space complexity : O(1)
    vector<int> dailyTemperatures(vector<int>& temp) {
        
        int n = temp.size()-1;
        vector<int>res(n+1,0);
        int warmest = INT_MIN;
        
        for(int i=n;i>=0;i--){
            if(temp[i] >= warmest){
                warmest = temp[i];
            }
            else{
                int iterator = i+1;
                while(temp[iterator]<=temp[i]){
                    iterator = iterator + res[iterator];
                }
                res[i] = iterator - i;
            }
        }
        
        return res;
    }
};
class Solution {
public:
    vector<int> plusOne(vector<int>& d) {
        for(int i=d.size()-1;i>=0;i--){
            if(d[i]==9) d[i]=0;
            else {
                d[i]+=1;
                return d;
            }
        }
        d.insert(d.begin(),1);
        return d;
    }
};
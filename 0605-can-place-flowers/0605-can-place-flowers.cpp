class Solution {
public:
    bool canPlaceFlowers(vector<int>& f, int n) {
        //just check if previous and next of current position is zero
        //if it is then place the flower and decrement n;
        for(int i=0;i<f.size();i++){
            int prev = (i==0 || f[i-1]==0) ? 0:1;
            int next = (i==f.size()-1 || f[i+1]==0) ? 0:1;
            if(f[i]==0 && prev==0 && next==0){
                f[i]=1;
                n--;
            }
        }
        return n<=0;
    }
};
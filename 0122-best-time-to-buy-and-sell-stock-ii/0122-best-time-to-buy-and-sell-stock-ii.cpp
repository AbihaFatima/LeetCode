class Solution {
public:
    int maxProfit(vector<int>& p) {
        int maxProfit=0;
        for(int i=0;i<p.size()-1;i++){
            if(p[i]<p[i+1]){
                int Profit = p[i+1]-p[i];
                maxProfit += Profit;
            }
        }
        return maxProfit;
    }
};
class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(begin(costs),end(costs));
        int count=0;
        for(auto i: costs){
            if(coins >=  i){
                count++;
                coins -= i;
            }
        }
        return count;
    }
};
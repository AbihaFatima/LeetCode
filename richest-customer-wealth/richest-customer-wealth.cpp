class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int wealth_sum = 0;
        int max_wealth = 0;
        for(int i=0; i<accounts.size(); i++)
        {
            wealth_sum =0;
            for(int j= 0; j<accounts[i].size(); j++)
            {
                wealth_sum = wealth_sum + accounts[i][j];
                
            }
            if(max_wealth<=wealth_sum)
            max_wealth = wealth_sum;
            else
                continue;
            
        }
        return max_wealth;
    }
};
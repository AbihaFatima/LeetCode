class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        
        vector<vector<double>>pyramid(102,vector<double>(102)); //As given in constraints
        pyramid[0][0] = (double)poured; //Explicit typecasting to double
        
        for(int i=0;i<=query_row;i++){
            for(int j=0;j<=i;j++){
                double flow = (pyramid[i][j]-1.0)/2;
                
                if(flow>0){ //If flow is zero then champagne is not excess so it will not be passed to other levels
                    pyramid[i+1][j] += flow; //passing flow to left glass(j) of next level(i+1)
                    pyramid[i+1][j+1] += flow;//passing flow to right glass(j+1) of next level(i+1)
                }
            }
        }
        double ans = min(1.0,pyramid[query_row][query_glass]);
        return ans;
    }
};
class Solution {
public:
    //TC: O(N^2) SC: O(N^2)
    vector<vector<int>> dp;
    int n, Finish;
    
    int getRoutes(vector<int>& locations, int currCity, int remFuel){
        if(remFuel < 0) return 0; // If remaining fuel is negative, no routes are possible
        if(dp[currCity][remFuel] != -1) return dp[currCity][remFuel];
        int ans;
        // If current city is the finishing city, there is one valid route
        if(currCity == Finish) ans=1; 
        else ans=0; // else, no valid routes yet
        //Generating routes from current city to other cities
        for(int nextCity=0; nextCity<n; nextCity++){
            if(nextCity != currCity){
                int currFuel = remFuel - abs(locations[currCity]-locations[nextCity]);
                ans = (ans + getRoutes(locations, nextCity, currFuel)) % 1000000007;
            }
        }
        return dp[currCity][remFuel] = ans;
    }
    
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        n = locations.size();
        dp = vector<vector<int>>(n, vector<int>(fuel + 1, -1));
        Finish = finish;
        for (auto& row : dp) {
            fill(row.begin(), row.end(), -1);
        }
        return getRoutes(locations,start,fuel);
    }
};
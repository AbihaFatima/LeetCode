class Solution {
public:
    //Time Complexity : O(NlogK)
    //Space Complexity : O(K)
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,pair<int,int>>> maxh;
        int n = points.size();
        //ans to contain the answer
        vector<vector<int>> ans;
        //loop through the matrix
        for(int i = 0;i<n;i++){
            //Push x^2+y^2 as it is relative
            //Push distance, coordinate in max heap
         maxh.push({(points[i][0]*points[i][0]) + (points[i][1]*points[i][1]),
         {points[i][0],points[i][1]}});
            //max heap keep the largest value at top 
            //we can remove the larger values than k until the size is < k
                while(maxh.size()>k)
                    maxh.pop(); //pop the > k value
            //sorting is done on the basis on distance from origin
            
        }
        
        //The left over elements in priority queue is the answer
        while(maxh.size()>0){
        pair<int,int> p = maxh.top().second; //store the second value which is coordinate in a pair
        ans.push_back({p.first,p.second}); //push the pair's first and second value, basically the coordinates
        maxh.pop(); //pop then and update the top
        }
        return ans;
        
    }

};
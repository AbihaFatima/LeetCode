class Solution {
public:
    /*  We can find that nth row we have [nC0,nC1,nC2,nC3...nCn] so only considering last line of Pascal's Triangle
    TimeComplexity : O(N)
    SpaceComplexity : O(1)
    */
    long double fact(int n){
        if(n<2) return 1;
        return n*fact(n-1);
    }
    vector<int> getRow(int rowIndex) {
        vector<int> result;
        for(int j=0;j<=rowIndex;j++){
            double temp = fact(rowIndex) / (fact(j)*fact(rowIndex-j));
            result.push_back(temp);
        }
        return result;
    }
};
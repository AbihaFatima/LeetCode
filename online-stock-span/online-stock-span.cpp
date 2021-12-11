class StockSpanner {
public:
    /*
    Time Complexity : O(N) all the elements are pushed and popped from the stack at most once. 
    Space Complexity : O(N)
    Algorithm used here is similar to stock span problem :
    1. Initialize span of day 1 (i=0) as 1 and put on to the stack.
    2. For i=1 to n, do following
        3. While price[stack.top()] < price[i] and !stack.isEmpty(), stack.pop()
            4. If price[stack.top()] > price[i], span = (i – stack.top())
            5. Push current day index i on to stack.
    6. return span
    */
    stack<pair<int, int>> s; // {{100, 1}, {80, 1}, {price, spans}}
    int index = 0;
    
    StockSpanner() {
        while(!s.empty())
        {
            s.pop();
        }
        index=0;
    }
    
    int next(int price) {
        
        int ans;
        if(s.empty())
        {
            s.push({price,index});
            ans=index+1;
        }
        
        else
        {
            while(!s.empty() && s.top().first<=price)
            {
                s.pop();
            }
            
            if(s.empty()){
                ans = index +1;
            }
            else{
                ans = index - s.top().second;
            }
            
            s.push({price,index});
        }
        
        index++;
        return ans;
 
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
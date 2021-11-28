//Time Complexity O(1);
//Space Complexity O(n);

class MinStack {
    stack<long long> Stack; 
    long long min; 
public:
    /** initialize your data structure here. */
    MinStack() {
        while(Stack.empty() == false) 
        {
            Stack.pop(); 
        }
        min = INT_MAX; 
    }
    
    void push(int value) {
        long long val = (long long)value;
        if(Stack.empty()) {
            min = val; 
            Stack.push(val); 
        }
        else {
            if(val < min) {
                Stack.push(2 * val * 1LL - min); //Push the modified value
                min = val; 
            }
            else {
                Stack.push(val); 
            }
        }
    }
    
    void pop() {
        if(Stack.empty()) return; 
        long long el = Stack.top(); 
        Stack.pop(); 
        
        if(el < min) { //Check if modified value is less than min; This happens after pop operation
            min = 2 * min - el; //If so switch to previous min ;
        }
    }
    
    int top() {
        if(Stack.empty()) 
            return -1; 
        
        long long el = Stack.top(); 
        if(el < min) //Again check with modified value
            return min; 
        return el; 
    }
    
    int getMin() {
        return min; 
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
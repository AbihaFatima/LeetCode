#include<queue>
class MyStack {
public:
    //Time Complexity : O(N^2)
    queue<int> q1,q2; 
    
    MyStack() {
        
    }

    void push(int x) {
         q1.push(x);
    }
    
    /* Removes the element on top of the stack and returns that element. */
    int pop() {
        
        int val;
        while (!q1.empty()) {
            val = q1.front();
            q1.pop();
            if (!q1.empty())
                q2.push(val);
        }
        while (!q2.empty()) {
            q1.push(q2.front());
            q2.pop();
        }
        return val; 
    }
    
    int top() {
        int topElement;
         while (!q1.empty()) {
            topElement = q1.front();
            q1.pop();
            q2.push(topElement);
        }
        while (!q2.empty()) {
            topElement = q2.front();
            q1.push(topElement);
            q2.pop();
        }
        return topElement;
    }
    
    bool empty() {
        return (q1.empty() && q2.empty());
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
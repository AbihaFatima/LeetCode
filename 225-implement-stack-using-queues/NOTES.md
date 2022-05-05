<hr>
<p>Time complexity if implemented using <strong>2 queues</strong>:<br>

In the above case, the push operation takes O(1) time because on each push operation the new element is added at the end of the Queue. On the other hand, pop operation takes O(n) because on each pop operation, all the elements are popped out from the Queue1 except the last element and pushed it into the Queue2. The last element from the Queue1 will be deleted and then all the elements from Queue2 are moved back to the Queue1.

Algorithm (when the pop operation is costly)

Push Algorithm:
The following are the steps to perform the push operation:

	Step 1: Consider two queues, i.e., Q1 and Q2, and the element to be inserted in the queue is x.

	Step 2: element= Q1.enqueue(x);

	Step 3: return element;

Pop Algorithm:
The following are the steps to delete an element from the queue:

	Step 1: Consider two queues, i.e., Q1 and Q2, and we want to remove an element from the queue.

	Step 2: if  !Q1.isEmpty() then

		     size:= Q1.size();

		     for i=0…size-1 do

		     Q2.enqueue(Q1.dequeue());

		     end

		     int item = Q1.dequeue();

		     for j=0…size-1 do

		     Q1.enqueue(Q2.dequeue());

		     end
</p>
<hr>
<p>Stack can be implemented using <strong>one queue also </strong><br>(Using single queue with O(n) push): </p>

```cpp
	
class MyStack {
public:
    queue<int> que;
    /** Initialize your data structure here. */
    MyStack() {
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        que.push(x);
        for(int i = 0; i<que.size()-1; i++) {
            que.push(que.front());
            que.pop();
        }
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int x = que.front();
        que.pop();
        return x;
    }
    
    /** Get the top element. */
    int top() {
        return que.front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return que.empty();
    }
};
				       
```

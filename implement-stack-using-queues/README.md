<h2>225. Implement Stack using Queues</h2><h3>Easy</h3><hr><div><p>Implement a last-in-first-out (LIFO) stack using only two queues. The implemented stack should support all the functions of a normal stack (<code>push</code>, <code>top</code>, <code>pop</code>, and <code>empty</code>).</p>

<p>Implement the <code>MyStack</code> class:</p>

<ul>
	<li><code>void push(int x)</code> Pushes element x to the top of the stack.</li>
	<li><code>int pop()</code> Removes the element on the top of the stack and returns it.</li>
	<li><code>int top()</code> Returns the element on the top of the stack.</li>
	<li><code>boolean empty()</code> Returns <code>true</code> if the stack is empty, <code>false</code> otherwise.</li>
</ul>

<p><b>Notes:</b></p>

<ul>
	<li>You must use <strong>only</strong> standard operations of a queue, which means that only <code>push to back</code>, <code>peek/pop from front</code>, <code>size</code> and <code>is empty</code> operations are valid.</li>
	<li>Depending on your language, the queue may not be supported natively. You may simulate a queue using a list or deque (double-ended queue) as long as you use only a queue's standard operations.</li>
</ul>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input</strong>
["MyStack", "push", "push", "top", "pop", "empty"]
[[], [1], [2], [], [], []]
<strong>Output</strong>
[null, null, null, 2, 2, false]

<strong>Explanation</strong>
MyStack myStack = new MyStack();
myStack.push(1);
myStack.push(2);
myStack.top(); // return 2
myStack.pop(); // return 2
myStack.empty(); // return False
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= x &lt;= 9</code></li>
	<li>At most <code>100</code> calls will be made to <code>push</code>, <code>pop</code>, <code>top</code>, and <code>empty</code>.</li>
	<li>All the calls to <code>pop</code> and <code>top</code> are valid.</li>
</ul>
<div>
<p>&nbsp;</p>
	
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
</div>

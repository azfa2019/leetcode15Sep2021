class MinStack {
  stack<int>stack0;
  stack<int>minStack;
  public:
  MinStack() {

  }

  void push(int val) {
    stack0.push(val);
    if(minStack.empty()) minStack.push(val);
    else minStack.push(min(minStack.top(),val));

  }

  void pop() {
    stack0.pop();
    minStack.pop();
  }

  int top() {
    return stack0.top();

  }

  int getMin() {
    return minStack.top();

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
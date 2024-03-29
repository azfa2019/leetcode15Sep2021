class MyQueue {
public:
    stack<int>a,b;
    MyQueue() {
        
    }
    
    void push(int x) {
        a.push(x);
    }
    
    int pop() {
        while(a.size()>1) b.push(a.top()),a.pop();
        int t=a.top();
        a.pop();
        while(b.size()) a.push(b.top()),b.pop();
        return t;
    }
    
    int peek() {
        while(a.size()>1) b.push(a.top()),a.pop();
        int t=a.top();
        while(b.size()) a.push(b.top()),b.pop();
        return t;
    }
    
    bool empty() {
        return a.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
class FreqStack {
    int n=0;
    unordered_map<int,int>cnt;
    unordered_map<int,stack<int>>stk;
public:
    FreqStack() {
        
    }
    
    void push(int val) {
        cnt[val]++;
        stk[cnt[val]].push(val);
        n=max(n,cnt[val]);
    }
    
    int pop() {
        int t=stk[n].top();
        stk[n].pop();
        cnt[t]--;
        if(stk[n].empty()) n--;
        return t;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */
class MaxStack {
public:
    /** initialize your data structure here. */
    MaxStack() {
    }
    
    void push(int x) {
        v.insert(v.begin(),x);
        m[x].push_back(v.begin());
    }
    
    int pop() {
        int x=*v.begin();
        m[x].pop_back();
        if(m[x].empty()) m.erase(x);
        v.erase(v.begin());
        return x;
    }
    
    int top() {
        return *v.begin();
    }
    
    int peekMax() {
        return m.rbegin()->first;
    }
    
    int popMax() {
        int x=m.rbegin()->first;
        auto it=m[x].back();
        m[x].pop_back();
        if(m[x].empty()) m.erase(x);
        v.erase(it);
        return x;
    }
private:
    list<int> v;
    map<int,vector<list<int>::iterator>> m;
};
class SmallestInfiniteSet {
public:
    int cnt[1001];
    priority_queue<int,vector<int>,greater<>>heap;
    SmallestInfiniteSet() {
        memset(cnt,0,sizeof cnt);
        for(int i=1;i<=1000;i++) heap.push(i),cnt[i]++; 
    }
    
    int popSmallest() {
        int x;
            x=heap.top();
            heap.pop();
            cnt[x]--;
        return x;
    }
    
    void addBack(int num) {
        //cout<<num<<" "<<cnt[num]<<endl;
          if(!cnt[num]){
            heap.push(num);
            cnt[num]++;
          }
        
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */
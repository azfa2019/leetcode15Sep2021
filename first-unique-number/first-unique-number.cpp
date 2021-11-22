class FirstUnique {
  queue<int>q0;
  unordered_map<int,bool>map0;
public:
    FirstUnique(vector<int>& nums) {
      for(int num:nums) add(num);
    }
    
    int showFirstUnique() {
      while(!q0.empty() && map0[q0.front()]==false){
        q0.pop();
      }
      return q0.empty()?-1:q0.front();
    }
    
    void add(int value) {
      if(map0.find(value)==map0.end()) {
        q0.push(value);
        map0[value]=true;
      }else map0[value]=false;
    }
};

/**
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique* obj = new FirstUnique(nums);
 * int param_1 = obj->showFirstUnique();
 * obj->add(value);
 */
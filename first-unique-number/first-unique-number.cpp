class FirstUnique {
  queue<int>q0;
  unordered_map<int,bool>unique;
public:
    FirstUnique(vector<int>& nums) {
        for (int num:nums) add(num);
    }
    
    int showFirstUnique() {
      while(!q0.empty()&&unique[q0.front()]==false) q0.pop();
      if(!q0.empty()) return q0.front();
      else return -1;
    }
    
    void add(int value) {
        if(unique.find(value)==unique.end()){
          unique[value]=true;
          q0.push(value);
        }else unique[value]=false;
    }
};

/**
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique* obj = new FirstUnique(nums);
 * int param_1 = obj->showFirstUnique();
 * obj->add(value);
 */
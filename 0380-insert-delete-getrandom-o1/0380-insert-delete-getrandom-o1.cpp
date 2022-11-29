class RandomizedSet {
public:
    vector<int>nums;
    unordered_map<int,int>hash;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(!hash.count(val)){
            nums.push_back(val);
            hash[val]=nums.size()-1;
            return true;
        }
        return false;
    }
    
    bool remove(int x) {
        if(hash.count(x)){
            int y=nums.back();
            int px=hash[x],py=hash[y];
            swap(nums[px],nums[py]);
            nums.pop_back();
            swap(hash[x],hash[y]);
            hash.erase(x);
            return true;
        }
        return false;
    }
    
    int getRandom() {
        return nums[rand()%nums.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int,int>hash;
        for(int n:nums) hash[n]++;
        int res=0;
        for(auto&p:hash){
            if(p.second>1) res+=p.second*(p.second-1)/2;
        }
        return res;
    }
};
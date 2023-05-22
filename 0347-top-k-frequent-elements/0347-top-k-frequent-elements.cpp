typedef pair<int,int> PII;
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>hash;
        for(int& num:nums) hash[num]++;
        int n=nums.size();
        vector<int>s(n+1);
        for(auto h:hash) s[h.second]++;
        int i=n,t=0;
        while(t<k) t+=s[i--];
        vector<int>res;
        for(auto [x,c]:hash) 
            if(c>i) res.push_back(x);
        return res;
    }
};
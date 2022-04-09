class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>hash;
        for(int num:nums) hash[num]++;
        priority_queue<pair<int,int>> pq;
        for(auto e:hash) pq.push({e.second,e.first});
        vector<int>res;
        while(k--){
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};
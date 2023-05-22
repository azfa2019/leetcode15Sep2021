typedef pair<int,int> PII;
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<PII>heap;
        unordered_map<int,int>hash;
        for(int& num:nums) hash[num]++;
        for(auto& h:hash) heap.push({h.second,h.first});
        vector<int>res;
        while(k--) res.push_back(heap.top().second),heap.pop();
        return res;
    }
};
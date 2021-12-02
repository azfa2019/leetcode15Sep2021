class Solution {
    struct compare{
        public:
        bool operator()(pair<int,int>&a,pair<int,int>&b){
            return a.first>b.first;
        }
    };
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,compare>pq;
        unordered_map<int,int>map;
        for(int num:nums) map[num]++;
        for(auto e:map){
            pq.push({e.second,e.first});
            if(pq.size()>k) pq.pop();
        }
       vector<int>ans;
        while(!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};

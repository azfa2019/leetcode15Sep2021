class Solution {
    struct compare{
        bool operator()(pair<int,int>&a,pair<int,int>&b){
            return a.first>b.first;
        }
    };
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        for(int num:nums) mp[num]++;
        priority_queue<pair<int,int>,vector<pair<int,int>>,compare>pq;
        for(auto e:mp){
            pq.push({e.second,e.first});
            if(pq.size()>k) pq.pop();
        }
        vector<int>ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};
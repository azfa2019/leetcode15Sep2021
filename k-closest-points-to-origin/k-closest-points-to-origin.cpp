class Solution {
    struct compare{
        bool operator()(vector<int>&p1,vector<int>&p2){
            return p1[0]*p1[0]+p1[1]*p1[1] < p2[0]*p2[0]+p2[1]*p2[1];
        }
    };
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<vector<int>,vector<vector<int>>,compare>pq;
        for(auto e:points){
            pq.push(e);
            if(pq.size()>k) pq.pop();
        }
        vector<vector<int>>ans;
        while(!pq.empty()) {
            ans.push_back(pq.top());
            pq.pop();
        }
        return ans;
    }
};
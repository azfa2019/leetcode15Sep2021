class Solution {
    public:
    vector<int> findMaximums(vector<int>& nums) {
        int n=nums.size();
        vector<int>prevLess(n,-1);
        vector<int>nextLess(n,n);
        stack<int>stck;
        for(int i=0;i<n;i++){
            while(!stck.empty() && nums[stck.top()]>nums[i]){
                nextLess[stck.top()]=i;
                stck.pop();
            }
            stck.push(i);
        }
        while(!stck.empty()) stck.pop();
        for(int i=n-1;i>=0;i--){
            while(!stck.empty() && nums[stck.top()]>nums[i]){
                prevLess[stck.top()]=i;
                stck.pop();
            }
            stck.push(i);
        }
        priority_queue<pair<int,int>>pq;
        for(int i=0;i<n;i++) pq.push({nums[i],i});
        vector<int>ans;
        for(int len=1;len<=n;len++){
            while(!pq.empty()){
                int idxMin=pq.top().second;
                if(nextLess[idxMin]-prevLess[idxMin]-1>=len) break;
                pq.pop();
            }
            ans.push_back(pq.top().first);
        }
        return ans;
    }
};
// 10 20 10 50 40 10
// 10 20 10 50 10 40
// query i: size=i+1
// i=1, 

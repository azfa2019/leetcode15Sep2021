class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        deque<pair<int,int>>dq;
        dq.push_back({nums[0],0});
        for(int i=1;i<nums.size();i++){
            while(dq.size() && dq.front().second<i-k) dq.pop_front();
            int res=dq.front().first+nums[i];
            while(dq.size() && dq.back().first<=res) dq.pop_back();
            dq.push_back({res,i});
        }
        return dq.back().first;
    }
};
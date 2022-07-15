class Solution {
public:
    vector<int> shortestDistanceColor(vector<int>& colors, vector<vector<int>>& queries) {
        int n=colors.size();
        unordered_map<int,vector<int>>m;
        for(int i=0;i<n;i++) m[colors[i]].push_back(i);
        vector<int>res;
        for(auto q:queries){
            int cur=INT_MAX;
            int t=q[0],c=q[1];
            if(!m.count(c)) {
                res.push_back(-1);
                continue;
            }
            int pos=closest(m[c],t);
            res.push_back(abs(pos-t));
        }
        return res;
    }
    int closest(vector<int>&nums,int t){
        int pos=lower_bound(nums.begin(),nums.end(),t)-nums.begin();
        if(pos==0) return nums[0];
        if(pos==nums.size()) return nums[nums.size()-1];
        if(nums[pos]-t<t-nums[pos-1]) return nums[pos];
        return nums[pos-1];
    }
};
// [1,1,2,1,3,2,2,3,3]
//  0 1 2 3 4 5 6 7 8
class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
       int n=nums.size(),mi=INT_MAX,res=INT_MAX;
        priority_queue<int>q;
        for(int i=0;i<n;i++){
            if(nums[i]&1) nums[i]*=2;
            q.push(nums[i]);
            mi=min(mi,nums[i]);
        }
        while(1){
            int tt=q.top();q.pop();
            res=min(res,tt-mi);
            if(tt&1) break;
            mi=min(mi,tt>>1);
            q.push(tt>>1);
        }
        return res;
    }
};
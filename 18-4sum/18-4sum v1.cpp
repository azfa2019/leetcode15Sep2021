class Solution {
    public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        for(int i=0;i<n-3;i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            if(nums[i]+nums[i+1]>target-(nums[i+2]+nums[i+3])) break;
            if(nums[i]+nums[n-1]<-nums[n-2]-nums[n-3]+target) continue;
            for(int j=i+1;j<n-2;j++){
                if(j>i+1 && nums[j]==nums[j-1]) continue;
                if(nums[i]+nums[j]>-nums[j+1]-nums[j+2]+target) break;
                if(nums[i]+nums[j]<-nums[n-2]-nums[n-1]+target) continue;
                int l=j+1,r=n-1;
                while(l<r){
                    long sum=nums[i]-(long) target+nums[j]+nums[l]+nums[r];
                    if(sum==0){
                        ans.push_back({nums[i],nums[j],nums[l],nums[r]});
                        l++,r--;
                        while(l<r && nums[l]==nums[l-1]) l++;
                        while(l<r && nums[r]==nums[r+1]) r--;
                    }else if(sum<0) l++;
                    else r--;
                }
            }
        }
        return ans;
    }
};

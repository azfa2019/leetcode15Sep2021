class Solution {
public:
    int minOperations(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int res=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            int j=i;
            while(j<n && nums[j]==nums[i]) j++;
            //cout<<"j:"<<j-i<<endl;
            int cnt=j-i;
            if(cnt==1) return -1;
            res+=(cnt+2)/3;
            i=j-1;
        }
        return res;
    }
};
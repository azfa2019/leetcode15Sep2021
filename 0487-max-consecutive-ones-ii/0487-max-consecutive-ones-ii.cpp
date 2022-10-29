class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return 1;
        vector<int>flip(n,0),noflip(n,0);
        int ans=0;
        if(nums[0]==1) flip[0]=1,noflip[0]=1;
        else flip[0]=1,noflip[0]=0;
        for(int i=1;i<n;i++){
            if(nums[i]==0) noflip[i]=0,flip[i]=noflip[i-1]+1;
            else noflip[i]=noflip[i-1]+1,flip[i]=flip[i-1]+1;
            ans=max(ans,max(noflip[i],flip[i]));
        }
        return ans;
    }
};
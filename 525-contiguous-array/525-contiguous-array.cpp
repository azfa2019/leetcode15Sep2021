class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n=nums.size();
        vector<int>s(n+1);
        int ans=0;
        int x=0;
        unordered_map<int,int>hash;
        hash[0]=0;
        for(int i=1;i<=n;i++){
            x+=nums[i-1]?1:-1;
            if(hash.count(x)) ans=max(ans,i-hash[x]);
            else hash[x]=i;
        }
        return ans;
    }
};

//0 1 0

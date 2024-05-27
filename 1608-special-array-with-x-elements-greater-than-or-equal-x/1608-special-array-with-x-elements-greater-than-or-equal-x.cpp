class Solution {
public:
    int specialArray(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        for(int x=1;x<=n;x++){
            if(x==n-1-(lower_bound(nums.begin(),nums.end(),x)-nums.begin())+1) return x;
        }
        return -1;
    }
};
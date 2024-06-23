class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int n=nums.size(),res=0;
        multiset<int>win;
        for(int l=0,r=0;r<n;r++){
            win.insert(nums[r]);
            while(*win.rbegin()-*win.begin()>limit){
                win.erase(win.find(nums[l++]));
            }
            res=max(res,r-l+1);
        }
        return res;
    }
};
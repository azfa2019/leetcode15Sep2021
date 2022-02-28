typedef long long LL;
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int n=nums.size();
        if(n==0) return {};
        vector<string>ans;
        LL i=0;
        while(i<n){
            LL j=i;
            while(j<n-1 && (LL)nums[j+1]-(LL)nums[j]==1) j++;
            string cur=to_string(nums[i]);
            if(i<j) cur+="->"+to_string(nums[j]); 
            ans.push_back(cur);
            i=j+1;
        }
        return ans;
    }
};

class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int,int>cnt1,cnt2;
        for(auto x:nums) cnt1[x]++;
        for(auto x:nums){
            if(!cnt1[x]) continue;
            if(cnt2[x-1]){
                cnt2[x-1]--;
                cnt2[x]++;
                cnt1[x]--; 
            }else if(cnt1[x+1] && cnt1[x+2]){
                cnt2[x+2]++;
                cnt1[x+2]--;
                cnt1[x+1]--;
                cnt1[x]--;
            }else return false;
        }
        return true;
    }
};
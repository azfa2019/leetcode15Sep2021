class Solution {
    public:
    int maxPower(string s) {
        int n=s.size();
        vector<int>mp(26,0);
        int ans=0;
        int left=0;
        for(int right=0;right<n;right++){
            char r=s[right];
            mp[r-'a']++;
            ans=max(ans,mp[r-'a']);
            if(left<n-1 && right-left+1>ans){
                mp[s[left]-'a']--;
                left++;
            }
        }
        return ans;
    }
};

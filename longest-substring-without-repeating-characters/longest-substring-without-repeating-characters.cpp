class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left=0;
        int n=s.size();
        int ans=0;
        unordered_map<char,int>mp;
        for(int right=0;right<n;right++){
            char r=s[right];
            mp[r]++;
            while(mp[r]>1){
                char l=s[left];
                mp[l]--;
                left++;
            }
            ans=max(ans,right-left+1);
        }
        return ans;
    }
};
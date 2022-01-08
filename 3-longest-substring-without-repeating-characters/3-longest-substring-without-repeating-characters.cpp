class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        int left=0;
        unordered_map<char,int>mp;
        int ans=0;
        for(int right=0;right<n;right++){
            mp[s[right]]++;
            while(mp[s[right]]>1){
                mp[s[left++]]--;
            }
            ans=max(ans,right-left+1);
        }
        return ans;
    }
};
class Solution {
public:
    int characterReplacement(string s, int k) {
        int ans=1;
        int n=s.size();
        int maxRepeat=1;
        int left=0;
        unordered_map<char,int>mp;
        for(int right=0;right<n;right++){
            char r=s[right];
            mp[r]++;
            maxRepeat=max(maxRepeat,mp[r]);
            while(right-left+1>maxRepeat+k) {
                char l=s[left];
                mp[l]--;
                left++;
            }
            ans=max(ans,right-left+1);
        }
        return ans;
    }
};
//AABABBA
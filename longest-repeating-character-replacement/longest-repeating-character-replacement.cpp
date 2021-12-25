class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int>mp;
        int left=0,right=0;
        int n=s.size();
        int maxRep=0,ans=0;
        for( right=0;right<n;right++){
            char r=s[right];
            mp[r]++;
            maxRep=max(maxRep,mp[r]);
            while(right-left+1>maxRep+k){
                char l=s[left++];
                mp[l]--;
            }
            ans=max(ans,right-left+1);
        }
        return ans;
    }
};
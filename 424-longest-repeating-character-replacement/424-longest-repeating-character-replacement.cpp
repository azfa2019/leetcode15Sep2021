class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.size();
        int left=0;
        unordered_map<char,int>mp;
        char r;
        int ans=0;
        int maxRep=0;
        for(int right=0;right<n;right++){
            r=s[right];
            mp[r]++;
            int maxRep=max(maxRep,mp[r]);
            while(right-left+1>maxRep+k){
                char l=s[left];
                left++;
                if(mp.find(l)!=mp.end()) mp[l]--;
            }
            ans=max(ans,right-left+1);
        }
        return ans;
    }
};
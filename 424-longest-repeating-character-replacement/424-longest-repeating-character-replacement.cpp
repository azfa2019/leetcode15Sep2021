class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.size();
        int left=0;
        int maxRep=0;
        unordered_map<char,int>mp;
        int ans=0;
        for(int right=0;right<n;right++){
            char r=s[right];
            mp[r]++;
            maxRep=max(maxRep,mp[r]);
            while(right-left+1>maxRep+k){
                char l=s[left++];
                if(mp.find(l)!=mp.end()) mp[l]--;
            }
            ans=max(ans,right-left+1);
        }
        return ans;
    }
};
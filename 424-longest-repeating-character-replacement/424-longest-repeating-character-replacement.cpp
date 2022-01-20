class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int>mp(26);
        int n=s.size();
        int left=0;
        int ans=0;
        for(int right=0;right<n;right++){
            char r=s[right];
            mp[r-'A']++;
            int maxRep=*max_element(mp.begin(),mp.end());
            while(left<n && right-left+1>maxRep+k){
                char l=s[left];
                left++;
                mp[l-'A']--;
            }
            ans=max(ans,right-left+1);
        }
        return ans;
    }
};
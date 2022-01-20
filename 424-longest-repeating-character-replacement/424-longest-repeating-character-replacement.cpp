class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int>mp(26);
        int n=s.size();
        int right=0;
        int ans=0;
        for(int left=0;left<n;left++){
            while(right<n && checkOk(right,s,left,mp,k)) {
                right++;
            }
            ans=max(ans,right-left);
            char l=s[left];
            mp[l-'A']--;
        }
        return ans;
    }
    bool checkOk(int right,string& s,int left,vector<int>&mp,int k){
        char r=s[right];
        mp[r-'A']++;
        int maxRep=*max_element(mp.begin(),mp.end());
        if(right-left+1<=maxRep+k) return true;
        mp[r-'A']--;
        return false;
    }
};
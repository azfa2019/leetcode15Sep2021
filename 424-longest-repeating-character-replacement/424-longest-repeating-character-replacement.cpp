class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.size();
        int right=0;
        vector<int>mp(26);
        int ans=0;
        for(int left=0;left<n;left++){
            while(right<n && checkOk(right,left,k,mp,s)) right++;
            ans=max(ans,right-left);
            char l=s[left];
            mp[l-'A']--;
        }
        return ans;
    }
    bool checkOk(int right,int left,int k,vector<int>&mp,string& s){
        char r=s[right];
        mp[r-'A']++;
        int rep=*max_element(mp.begin(),mp.end());
        if(rep+k>=right-left+1) return true;
        mp[r-'A']--;
        return false;
    }
};
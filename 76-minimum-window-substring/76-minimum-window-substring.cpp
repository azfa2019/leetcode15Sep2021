class Solution {
    public:
    string minWindow(string s, string t) {
        unordered_map<char,int>mp;
        for(char c:t) mp[c]++;
        int left=0;
        int n=s.size();
        int count=0;
        int ans=INT_MAX,start=0;
        for(int right=0;right<n;right++){
            char r=s[right];
            if(mp.find(r)!=mp.end()) {
                mp[r]--;
                if(mp[r]==0) count++;
            }
            while(count==mp.size()){
                char l=s[left];
                left++;
                if(mp.find(l)!=mp.end()){
                    if(mp[l]==0) count--;
                    mp[l]++;
                }
                if (ans>right-left+2){
                    ans=right-left+2;
                    start=left-1;
                }
            }
        }
        return ans==INT_MAX?"":s.substr(start,ans);
    }
};
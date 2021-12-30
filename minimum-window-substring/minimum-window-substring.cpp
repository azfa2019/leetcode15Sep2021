class Solution {
    public:
    string minWindow(string s, string t) {
        int m=s.size(),n=t.size();
        int left=0;
        unordered_map<char,int>mp;
        for(char c:t) mp[c]++;
        int count=0;
        string ans="";
        int minLen=INT_MAX;
        for(int right=0;right<m;right++){
            char r=s[right];
            if(mp.find(r)!=mp.end()){
                mp[r]--;
                if(mp[r]==0) count++;
            }
            while(count==mp.size()){
                if(right-left+1<minLen){
                    minLen=right-left+1;
                    ans=s.substr(left,minLen);
                }
                char l=s[left++];
                if(mp.find(l)!=mp.end()){
                    if(mp[l]==0) count--;
                    mp[l]++;
                }
            }
        }
        return ans;
    }
};
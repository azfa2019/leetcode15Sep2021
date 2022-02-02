class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int m=p.size();
        int n=s.size();
        int left=0;
        int count=0;
        unordered_map<char,int>mp;
        for(auto c:p) mp[c]++;
        vector<int>ans;
        for(int right=0;right<n;right++){
            char r=s[right];
            if(mp.find(r)!=mp.end()){
                mp[r]--;
                if(mp[r]==0) count++;
            }
            if(right-left+1>m){
                char l=s[left];
                left++;
                if(mp.find(l)!=mp.end()) {
                    if(mp[l]==0) count--;
                    mp[l]++;
                }
            }
            if(count==mp.size()) ans.push_back(left);
        }
        return ans;
    }
};
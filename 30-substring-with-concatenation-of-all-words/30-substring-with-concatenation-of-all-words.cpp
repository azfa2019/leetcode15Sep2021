class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int>res;
        if(words.empty()) return res;
        int n=s.size(),m=words.size(),w=words[0].size();
        unordered_map<string,int>tot;
        for(auto& w:words) tot[w]++;
        for(int i=0;i<w;i++){
            unordered_map<string,int>wd;
            int cnt=0;
            for(int j=i;j+w-1<n;j+=w){
                if(j>=i+m*w){
                    auto word=s.substr(j-m*w,w);
                    wd[word]--;
                    if(wd[word]<tot[word]) cnt--;
                }
                auto word=s.substr(j,w);
                wd[word]++;
                if(wd[word]<=tot[word]) cnt++;
                if(cnt==m) res.push_back(j-(m-1)*w);
            }
        }
        return res;
    }
};
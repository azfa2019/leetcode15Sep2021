class Solution {
    public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<string>q;
        q.push(beginWord);
        unordered_set<string>words;
        for(auto s:wordList) words.insert(s);
        unordered_map<string,int>dist;
        dist[beginWord]=1;
        while(q.size()){
            auto cur=q.front();q.pop();
            auto tmp=cur;
            for(int i=0;i<tmp.size();i++){
                cur=tmp;
                for(int c='a';c<='z';c++){
                    if(c!=tmp[i]) {
                        cur[i]=c;
                        if(words.count(cur) && !dist.count(cur)) {
                            dist[cur]=dist[tmp]+1;
                            if(cur==endWord) return dist[cur];
                            q.push(cur);
                        }
                    }
                }
            }
        }
        return 0;
    }
};
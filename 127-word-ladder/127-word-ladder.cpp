class Solution {
    public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<string>q;
        q.push(beginWord);
        unordered_set<string>words;
        for(auto s:wordList) words.insert(s);
        unordered_map<string,int>hash;
        hash[beginWord]=1;
        while(q.size()){
            auto cur=q.front();q.pop();
            string tmp=cur;
            for(int i=0;i<tmp.size();i++){
                cur=tmp;
                for(char c='a';c<='z';c++){
                    if(cur[i]!=c){
                        cur[i]=c;
                        if(words.count(cur) && !hash.count(cur)){
                            hash[cur]=hash[tmp]+1;
                            if(cur==endWord) return hash[cur];
                            q.push(cur);
                        }

                    }
                }
            }
        }
        return 0;
    }
};
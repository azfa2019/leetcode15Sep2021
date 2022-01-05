class Solution {
public:
    string alienOrder(vector<string>& words) {
        unordered_map<char,vector<char>>g;
        unordered_map<char,int>indegree;
        int n=words.size();
        for(string w:words){
            for(char c:w) indegree[c]=0;
        }
        for(int i=0;i<n-1;i++){
            if(words[i].find(words[i+1])==0 && words[i].size()>words[i+1].size()) return "";
            for(int j=0;j<min(words[i].size(),words[i+1].size());j++){
                if(words[i][j]==words[i+1][j]) continue;
                g[words[i][j]].push_back(words[i+1][j]);
                indegree[words[i+1][j]]++;
                break;
            }
        }
        queue<char>source;
        for(auto e:indegree){
            if(e.second==0) source.push(e.first);
        }
        string ans="";
        while(source.size()){
            char cur=source.front();source.pop();
            ans.push_back(cur);
            for(char next:g[cur]){
                indegree[next]--;
                if(indegree[next]==0) source.push(next);
            }
        }
        return ans.size()==indegree.size()?ans:"";
    }
};
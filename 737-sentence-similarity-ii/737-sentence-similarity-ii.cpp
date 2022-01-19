class Solution {
    class UF{
        public:
        unordered_map<string,string>parent;
        unordered_map<string,int>rank;
        UF(vector<string>words){
            for(string w:words) {
                rank[w]=0;
                parent[w]=w;
            }
        }
        string findParent(string s){
            if(parent[s]!=s) parent[s]=findParent(parent[s]);
            return parent[s];
        }
        bool unionNodes(string&x, string& y){
            x=findParent(x);
            y=findParent(y);
            if(x==y) return false;
            if(rank[x]<rank[y]) parent[x]=y;
            else if(rank[x]>rank[y]) parent[y]=x;
            else parent[y]=x,rank[x]++;
            return true;
        }
    };
    public:
    bool areSentencesSimilarTwo(vector<string>& sentence1, vector<string>& sentence2, vector<vector<string>>& similarPairs) {
        unordered_set<string>st;
        if(sentence1.size()!=sentence2.size()) return false;
        int n=sentence1.size();
        for(auto s:sentence1) st.insert(s);
        for(auto s:sentence2) st.insert(s);
        for(auto item: similarPairs) st.insert(item[0]),st.insert(item[1]);
        vector<string>words(st.begin(),st.end());
        UF uf=UF(words);
        for(auto item:similarPairs){
            uf.unionNodes(item[0],item[1]);
        }
        for(int i=0;i<n;i++){
            if(uf.findParent(sentence1[i])!=uf.findParent(sentence2[i])) return false;
        }
        return true;
    }
};
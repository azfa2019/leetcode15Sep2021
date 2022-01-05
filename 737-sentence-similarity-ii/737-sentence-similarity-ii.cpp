class Solution {
    class UF{
        public:
        unordered_map<string,string>parent;
        unordered_map<string,int>rank;
        UF(vector<string>words){
            for(int i=0;i<words.size();i++){
                parent[words[i]]=words[i];
                rank[words[i]]=0;   
            } 
        }
        bool unionNodes(string& s1,string& s2){
            string p1=findParent(s1);
            string p2=findParent(s2);
            if(p1==p2) return false;
            if(rank[p1]<rank[p2]) parent[p1]=p2;
            else if(rank[p1]>rank[p2]) parent[p2]=p1;
            else parent[p1]=p2,rank[p2]++;
            return true;
        }
        string findParent(string& s){
            if(s!=parent[s]) parent[s]=findParent(parent[s]);
            return parent[s];
        }
    };
    public:
    bool areSentencesSimilarTwo(vector<string>& sentence1, vector<string>& sentence2, vector<vector<string>>& similarPairs) {
        unordered_set<string>words;
        int n=sentence1.size();
        if(sentence2.size()!=n) return false;
        for(int i=0;i<n;i++){
            words.insert(sentence1[i]);
            words.insert(sentence2[i]);
        }
        for(auto p:similarPairs){
            words.insert(p[0]);
            words.insert(p[1]);
        }
        vector<string>all(words.begin(),words.end());
        UF uf=UF(all);
        for(auto p:similarPairs)
            uf.unionNodes(p[0],p[1]);
        for(int i=0;i<n;i++){
            if(sentence1[i]==sentence2[i]) continue;
            if(uf.findParent(sentence1[i])!=uf.findParent(sentence2[i])) return false;
        }
        return true;
    }
};
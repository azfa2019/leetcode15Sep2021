class Solution {
    class UF{
        public:
        vector<int>parent;
        vector<int>rank;
        UF(int n){
            parent=vector<int>(n,0);
            rank=vector<int>(n,0);
            for(int i=0;i<n;i++) parent[i]=i;
        }
        bool unionNodes(int n1,int n2){
            int p1=findParent(n1);
            int p2=findParent(n2);
            if(p1==p2) return false;
            if(rank[p1]<rank[p2]) parent[p1]=p2;
            else if(rank[p1]>rank[p2]) parent[p2]=p1;
            else parent[p1]=p2,rank[p2]++;
            return true;
        }
        int findParent(int n){
            if(n!=parent[n]) parent[n]=findParent(parent[n]);
            return parent[n];
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
        unordered_map<string,int>mp;
        int count=0;
        for(auto s:words) mp[s]=count++;
        UF uf=UF(words.size());
        for(auto p:similarPairs)
            uf.unionNodes(mp[p[0]],mp[p[1]]);
        for(int i=0;i<n;i++){
            if(uf.findParent(mp[sentence1[i]])!=uf.findParent(mp[sentence2[i]])) return false;
        }
        return true;
    }
};
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
        if(rank[p1]>rank[p2]) parent[p2]=p1;
        else if(rank[p1]<rank[p2]) parent[p1]=p2;
        else parent[p1]=p2,rank[p2]++;
        return true;
    }
    int findParent(int i){
        if(i!=parent[i]) parent[i]=findParent(parent[i]);
        return parent[i];
    }
};
class Solution {
    public:
    bool areSentencesSimilarTwo(vector<string>& sentence1, vector<string>& sentence2, vector<vector<string>>& similarPairs) {
        if(sentence1.size()!=sentence2.size()) return false;
        unordered_set<string>st;
        for(int i=0;i<sentence1.size();i++){
            st.insert(sentence1[i]);
            st.insert(sentence2[i]);
        }
        int i=1;
        unordered_map<string,int>mp;
        for(auto e:st){
            mp[e]=i++;
        }
        int n=st.size();
        UF uf=UF(n+1);
        for(auto e:similarPairs){
            uf.unionNodes(mp[e[0]],mp[e[1]]);
        }
        for(int i=0;i<sentence1.size();i++ ){
            if(uf.findParent(mp[sentence1[i]])!=uf.findParent(mp[sentence2[i]]))  return false;
        }
        return true;
    }
};
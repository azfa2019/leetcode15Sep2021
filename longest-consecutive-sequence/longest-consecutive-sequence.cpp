class UF{
    public:
    vector<int>parent;
    vector<int>rank;
    UF(int n){
        parent=vector<int>(n,0);
        for(int i=0;i<n;i++) parent[i]=i;
        rank=vector<int>(n,0);
    }
    int findParent(int x){
        if(x!=parent[x]) parent[x]=findParent(parent[x]);
        return parent[x];
    }
    bool unionNodes(int x,int y){
        int px=findParent(x);
        int py=findParent(y);
        if(px==py) return false;
        if(rank[px]<rank[py]) 
            parent[px]=py;
        else if(rank[px]>rank[py]) parent[py]=px;
        else{
            parent[py]=px;
            rank[px]++;
        }
        return true;
    }
};
class Solution {
    public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++) mp[nums[i]]=i;
        UF uf=UF(n);
        for(int num:nums) {
            if(mp.find(num+1)!=mp.end()){
                uf.unionNodes(mp[num],mp[num+1]);
            }
        }
        unordered_map<int,int>mp2;
        int ans=0;
        for(auto e:mp){
            int root=uf.findParent(e.second);
            mp2[root]++;
            ans=max(ans,mp2[root]);
        }
        return ans;
    }
};
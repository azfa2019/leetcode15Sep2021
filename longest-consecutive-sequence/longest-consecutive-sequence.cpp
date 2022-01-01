class Solution {
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
    public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>st(nums.begin(),nums.end());
        unordered_map<int,int>mp;
        int count=0;
        for(int num:st) mp[num]=count++;
        UF uf=UF(count);
        for(int num:st) 
            if(mp.find(num+1)!=mp.end())
                uf.unionNodes(mp[num],mp[num+1]);
        unordered_map<int,int>pmap;
        int ans=0;
        for(int num:st) {
            int p=uf.findParent(mp[num]);
            pmap[p]++;
            ans=max(ans,pmap[p]);
        }
        return ans;
    }
};
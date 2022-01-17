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
        bool unionNodes(int x1,int x2){
            int p1=findParent(x1);
            int p2=findParent(x2);
            if(p1==p2) return false;
            if(rank[p1]>rank[p2]) parent[p2]=p1;
            else if(rank[p2]>rank[p1]) parent[p1]=p2;
            else{
                parent[p1]=p2;
                rank[p2]++;
            }
            return true;
        }
        int findParent(int x){
            if(parent[x]!=x) parent[x]=findParent(parent[x]);
            return parent[x];
        }
    };
public:
    int longestConsecutive(vector<int>& nums) {
        //nums.erase(unique(nums.begin(),nums.end()),nums.end());
        int n=nums.size();
        UF uf=UF(n);
        unordered_map<int,int>indexMp;
        for(int i=0;i<n;i++) indexMp[nums[i]]=i;
        for(int i:nums){
            if(indexMp.find(i+1)!=indexMp.end())
                uf.unionNodes(indexMp[i],indexMp[i+1]);
        }
        unordered_map<int,int>mp;
        int ans=0;
        for(auto item:indexMp){
            int p=uf.findParent(indexMp[item.first]);
            mp[p]++;
            ans=max(ans,mp[p]);
        }
        return ans;
    }
};
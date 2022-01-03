class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        unordered_map<int,vector<int>>mp;
        for(int i=1;i<=n;i++) mp[i]={};
        unordered_set<int>st;
        for(auto e:trust){
            mp[e[0]].push_back(e[1]);
        }
        vector<int>ans;
        for(auto e:mp){
            //cout<<e.first<<" "<<e.second.size()<<" "<<endl;
            if(e.second.size()==0) ans.push_back(e.first);
        }
        if(ans.size()!=1) return -1; 
        int count=n-1;
        for(auto e:trust) if(e[1]==ans[0]) count--;
        return count==0?ans[0]:-1;
    }
};

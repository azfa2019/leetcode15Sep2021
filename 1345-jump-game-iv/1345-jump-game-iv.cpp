class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n=arr.size();
        if(n==1) return 0;
        queue<int>q;
        vector<int>visited(n,0);
        q.push(0);
        visited[0]=1;
        unordered_map<int,vector<int>>mp;
        for(int i=0;i<n;i++) mp[arr[i]].push_back(i);
        int count=0;
        while(q.size()){
            int level=q.size();
            while(level--){
                int cur=q.front();q.pop();
                if(cur+1<n && visited[cur+1]==0) 
                    q.push(cur+1),visited[cur+1]=1;
                if(cur-1>=0 && visited[cur-1]==0) 
                    q.push(cur-1),visited[cur-1]=1;
                for(int next:mp[arr[cur]]){
                    if(visited[next]==0) q.push(next);
                    visited[next]=1;
                }
                mp.erase(arr[cur]);
            }
            count++;
            if(visited[n-1]==1) return count;
        }
        return -1;
    }
};
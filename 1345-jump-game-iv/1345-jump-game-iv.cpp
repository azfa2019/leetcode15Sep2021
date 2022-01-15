class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n=arr.size();
        if(n==1 ) return 0;
        unordered_map<int,vector<int>>mp;
        vector<int>visited(n,0);
        for(int i=0;i<n;i++) mp[arr[i]].push_back(i);
        queue<int>q;
        q.push(0);
        visited[0]=1;
        int count=0;
        while(q.size()){
            int levelSize=q.size();
            while(levelSize--){
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
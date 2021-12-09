class Solution {
    int n;
public:
    bool canReach(vector<int>& arr, int start) {
        this->n=arr.size();
        vector<bool> visited(n,false);
        queue<int>q;
        //visited[start]=true;
        q.push(start);
        while(!q.empty()){
            int cur=q.front();q.pop();
            if(arr[cur]==0) return true;
            //if(visited[cur]==true) continue;
            int left=cur-arr[cur];
            if(left>=0 && left<n && visited[left]==false){
                visited[left]=true;
                q.push(left);
            }
            int right=cur+arr[cur];
            if(right<=n-1 && right>=0 && visited[right]==false){
                visited[right]=true;
                q.push(right);
            }
        }
        return false;
    }
};
class Solution {
    int n;
public:
    bool canReach(vector<int>& arr, int start) {
        this->n=arr.size();
        vector<bool> visited(n,false);
        return dfs(start,arr,visited);
    }
    bool dfs(int curIdx,vector<int>& arr,vector<bool>&visited){
        if(curIdx>n-1 || curIdx<0 || visited[curIdx]==true) return false;
        visited[curIdx]=true;
        if(arr[curIdx]==0) return true;
        return dfs(curIdx+arr[curIdx],arr,visited) || dfs(curIdx-arr[curIdx],arr,visited);
    }
};
class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        int n=arr.size();
        sort(arr.begin(),arr.end());
        vector<vector<int>>ans;
        int minDiff=abs(arr[0]-arr[1]);
        for(int i=0;i<n-1;i++){
            if(abs(arr[i]-arr[i+1])<minDiff) {
                minDiff=abs(arr[i]-arr[i+1]);
                ans.clear();
                ans.push_back({arr[i],arr[i+1]});
            }else if(abs(arr[i]-arr[i+1])==minDiff)
                ans.push_back({arr[i],arr[i+1]});
        }
        return ans;
    }
};
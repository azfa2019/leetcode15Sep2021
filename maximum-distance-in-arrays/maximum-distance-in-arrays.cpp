class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int n=arrays.size();
        int ans=0,minVal=arrays[0][0],maxVal=arrays[0].back();
        for(int i=1;i<n;i++){
            ans=max(ans,max(abs(arrays[i].back()-minVal),abs(arrays[i][0]-maxVal)));
            minVal=min(minVal,arrays[i][0]);
            maxVal=max(maxVal,arrays[i].back());
        }
        return ans;
    }
};
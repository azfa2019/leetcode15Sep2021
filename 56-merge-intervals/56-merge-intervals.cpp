class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n=intervals.size();
        sort(intervals.begin(),intervals.end());
        vector<vector<int>>ans;
        for(int i=0;i<n;i++){
            ans.push_back(intervals[i]);
            while(i<n && intervals[i][0]<=ans.back()[1]) {
                ans.back()[1]=max(ans.back()[1],intervals[i][1]);
                i++;
            }
            i--;
        }
        return ans;
    }
};
// 1   3 
//   2.         6
//                  8.  10
//                          15   18
// 
// 
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n=intervals.size();
        sort(intervals.begin(),intervals.end());
        vector<vector<int>>ans{intervals[0]};
        for(int i=1;i<n;i++){
            while(i<n && intervals[i][0]<=ans.back()[1]) {
                ans.back()[1]=max(ans.back()[1],intervals[i][1]);
                i++;
            }
           if(i<n) ans.push_back(intervals[i]);
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
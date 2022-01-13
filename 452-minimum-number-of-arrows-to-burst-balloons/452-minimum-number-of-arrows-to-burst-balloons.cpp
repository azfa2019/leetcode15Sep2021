class Solution {
    struct compare{
        bool operator()(vector<int>&a,vector<int>&b){
            return a[1]<b[1];
        }
    };
    typedef long long LL;
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        //find how many don't overlap
        int n=points.size();
        sort(points.begin(),points.end(),compare());
        int count=1;
        int end=points[0][1];
        for(int i=1;i<n;i++){
            if(points[i][0]<=end) continue;
            end=points[i][1];
            count++;
        }
        return count;
    }
};
// 1.  6
//   2.    8
//       7.    12
//          10.   16
// 
//  xxxxx
//    xxxxxx
//     xxxxxxxxxx
//        xxxxxxxxx    
//  1. 2
//       3. 4
//            5. 6
//                  7 8
// 1. 2
//.   2. 3
//       3. 4
//          4. 5
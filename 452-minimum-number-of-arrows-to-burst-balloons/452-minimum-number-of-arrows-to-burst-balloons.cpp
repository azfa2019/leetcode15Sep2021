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
        int count=0;
        LL end=LLONG_MIN;
        for(auto p:points){
            if(p[0]<=end) continue;
            count++;
            end=p[1];
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
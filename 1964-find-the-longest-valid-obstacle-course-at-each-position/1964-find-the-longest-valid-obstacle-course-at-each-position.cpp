class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& a) {
        int n=a.size();
        vector<int>tails;
        vector<int>ans(n);
        tails.push_back(0);
        for(int i=0;i<n;i++){
            int l=0,r=tails.size();
            while(l<r){
                int m=(l+r)>>1;
                if(tails[m]>a[i]) r=m;
                else l=m+1;
            }
            if(l==tails.size()) tails.push_back(a[i]);
            else tails[l]=a[i];
            ans[i]=l;
        }
        return ans;
    }
};
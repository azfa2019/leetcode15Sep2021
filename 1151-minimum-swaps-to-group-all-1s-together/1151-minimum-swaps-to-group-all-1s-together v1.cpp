class Solution {
public:
    int minSwaps(vector<int>& data) {
        int n=accumulate(data.begin(),data.end(),0);
        int left=-n,right=0,cnt=0;
        int res=0;
        while(right<data.size()){
            if(data[right]==1) cnt++;
            if(left>=0 && data[left]==1) cnt--;
            res=max(res,cnt);
            left++,right++;
        }
        return n-res;
    }
};

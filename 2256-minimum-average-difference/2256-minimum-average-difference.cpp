typedef long long LL;
class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        LL prefix=0,suffix=accumulate(nums.begin(),nums.end(),0LL);
        int res=0,min=INT_MAX;
        int n=nums.size();
        for(int i=0;i<n;i++){
            prefix+=nums[i],suffix-=nums[i];
            LL cur=abs(prefix/(i+1)-((n-i-1==0)?0:suffix/(n-i-1)));
            if(cur<min){
                min=cur;
                res=i;
            }
        }
        return res;
    }
};
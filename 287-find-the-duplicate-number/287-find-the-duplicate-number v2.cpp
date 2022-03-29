class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int len=nums.size();
        int l=1,r=len-1;
        while(l<r){
            int m=l+r>>1;
            int cnt=0;
            for(int num:nums) 
                if(num<=m) cnt++;
            if(cnt>m) r=m;
            else l=m+1;
        }
        return l;
    }
};

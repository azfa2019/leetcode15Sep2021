class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int r,cnt=0;
        for(int num:nums){
            if(!cnt) r=num,cnt=1;
            else if(num==r) cnt++;
            else cnt--;
        }
        return r;
    }
};

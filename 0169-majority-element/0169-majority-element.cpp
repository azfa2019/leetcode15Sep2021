class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int r,c=0;
        for(int x:nums){
            if(!c) r=x,c=1;
            else if(x!=r) c--;
            else c++;
        }
        return r;
    }
};
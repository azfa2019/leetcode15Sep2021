class Solution {
public:
    int maximum69Number (int num) {
        int res=0;
        vector<int>nums;
        while(num>0){
            nums.push_back(num%10);
            num/=10;
        }
        for(int i=nums.size()-1;i>=0;i--)
            if(nums[i]==6) {nums[i]=9;break;}
        for(int i=nums.size()-1;i>=0;i--) res=res*10+nums[i];
        return res;
    }
};
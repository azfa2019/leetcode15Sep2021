class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        for(int i=nums.size()-1;i>=2;i--){
            int a=nums[i-1],b=nums[i-2],c=nums[i];
            if(a+b>c) return a+b+c;
        }
        return 0;
    }
};
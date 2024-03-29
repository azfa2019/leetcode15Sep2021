class Solution {
public:
    // see https://leetcode.cn/problems/132-pattern/solutions/676970/xiang-xin-ke-xue-xi-lie-xiang-jie-wei-he-95gt/
    bool find132pattern(vector<int>& nums) {
        stack<int>stk;
        int right=INT_MIN;
        for(int i=nums.size()-1;i>=0;i--){
            if(nums[i]<right) return true;
            while(stk.size()&&nums[i]>stk.top()) right=max(right,stk.top()),stk.pop();
            stk.push(nums[i]);
        }
        return false;
    }
};
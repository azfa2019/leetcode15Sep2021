class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        int ans=0,slow=1;
        if(n<=2) return n;
        for(int i=2;i<n;i++){
           if(nums[slow]!=nums[slow-1]) {
               slow++;
               nums[slow]=nums[i];
           } else {
                while(i<n && nums[i]==nums[slow]) i++;
                if(slow<n && i<n) {
                    slow++;
                    nums[slow]=nums[i];
                }
            }
        }
        return slow+1;
    }
};
// 1,1,1
//   s i
class Solution {
public:
    int missingElement(vector<int>& nums, int k) {
        int n=nums.size();
        int l=0,r=n-1;
        while(l<r){
            int mid=(l+r+1)>>1;
            if(nums[mid]-nums[0]-mid<k) l=mid;
            else r=mid-1;
        }
        cout<<l<<endl;
        return nums[0]+k+l;
    }
};
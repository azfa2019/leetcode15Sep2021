class Solution {
public:
    int qsort(vector<int>& nums,int l,int r,int k){
        if(l==r) return nums[k];
        int i=l-1,j=r+1,x=nums[(l+r)/2];
        while(i<j){
            while(nums[++i]>x);
            while(nums[--j]<x);
            if(i<j) swap(nums[i],nums[j]); 
        }
        if(k<=j) return qsort(nums,l,j,k);
        return qsort(nums,j+1,r,k);
    }
    int findKthLargest(vector<int>& nums, int k) {
        return qsort(nums,0,nums.size()-1,k-1);
    }
};
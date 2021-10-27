class Solution {
public:
    void sortColors(vector<int>& nums) {
      // 2 0 2 1 1 0
      // 0 0 2 1 1 2
      //left: 0 pointer
      //i: 1 pointer
      //right: 2 pointer
      int i=0,left=0,right=nums.size()-1;
      while(i<=right){
        if(nums[i]==0) swap(left,i,nums),left++,i++;
        else if(nums[i]==1) i++;
        else swap(i,right,nums),right--;
      }
    }
  void swap(int i,int j,vector<int>&nums){
    int tmp=nums[i];
    nums[i]=nums[j];
    nums[j]=tmp;
  }
};
class Solution {
  public:
  vector<int> findDisappearedNumbers(vector<int>& nums) {
    int i=0;
    int n=nums.size();
    while(i<n){
      if(nums[nums[i]-1]!=nums[i]) swap(nums,i,nums[i]-1);
      else i++;
    }
    vector<int>ans;
    for(int i=0;i<n;i++) if(nums[i]-1!=i) ans.push_back(i+1);
    return ans;
  }
  void swap(vector<int>&nums,int i,int j){
    int tmp=nums[i];
    nums[i]=nums[j];
    nums[j]=tmp;
  }
};
//0 1 2 3 4 5 6 7    i, nums[i], nums[i]-1, nums[nums[i]-1]
//-----------------  
//4 3 2 7 8 2 3 1,   0, 4,       3,         7               swap 3,0
//7 3 2 4 8 2 3 1,   0, 7,       6,         3,              swap 6,0
//3 3 2 4 8 2 7 1,   0, 3,       2,         2,              swap 2,0
//2 3 3 4 8 2 7 1,   0, 2,       1,         3,              swap 1,0
//3 2 3 4 8 2 7 1,   0, 3,       2,         2,              i++
//3 2 3 4 8 2 7 1,   1, 2,       1,         2,              i++
//3 2 3 4 8 2 7 1,   2, 3,       2,         3,              i++
//3 2 3 4 8 2 7 1,   3, 4,       3,         4,              i++
//3 2 3 4 8 2 7 1,   4, 8,       7,         1,              swap 4,7
//3 2 3 4 1 2 7 8,   4, 1,       0,         3,              swap 4,0
//1 2 3 4 3 2 7 8,   4, 1,       0,         3,              swap 4,0

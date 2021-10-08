class Solution {
  public:
  bool judgePoint24(vector<int>& cards) {
    vector<double>nums;
    for(int i:cards) nums.push_back(i*1.0);
    return helper(nums);

  }
  bool helper(vector<double>&nums){
    int m=nums.size();
    if(m==1) {
      //cout<<cards[0]<<endl;
      return abs(nums[0]-24.)<1e-5;
    }
    for(int i=0;i<m;i++){
      for(int j=0;j<m;j++){
        if(i==j) continue;
        vector<double>cur;
        for(int k=0;k<m;k++){
          if(k!=i && k!=j) cur.push_back(nums[k]);
        }
        double a=nums[i],b=nums[j];
        cur.push_back(a+b); if(helper(cur)) return true; cur.pop_back();  
        cur.push_back(a-b);if(helper(cur)) return true;cur.pop_back();  
        cur.push_back(a*b);if(helper(cur)) return true;cur.pop_back();  
        if(b!=0.) {cur.push_back(a/b);if(helper(cur)) return true;cur.pop_back();}  
      }
    }
    return false;
  }
};
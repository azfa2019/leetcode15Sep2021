class Solution {
  public:
  vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    unordered_map<int,int>map;
    for(int i=0;i<nums2.size();i++){
      for(int j=i+1;j<nums2.size();j++){
        if(nums2[j]>nums2[i]) {
          map[nums2[i]]=nums2[j];
          break;
        }
      }
    }
    //for(auto e:map) cout<<e.first<<","<<e.second<<endl;
    vector<int>ans;
    for(int num:nums1){
      if(map.find(num)==map.end())  ans.push_back(-1);
      else ans.push_back(map[num]);
    } 
    return ans;
  }
};
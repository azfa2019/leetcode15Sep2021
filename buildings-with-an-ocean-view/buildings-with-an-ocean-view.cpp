class Solution {
public:
    vector<int> findBuildings(vector<int>& heights) {
      int n=heights.size();
      unordered_map<int,int>map0;
      for(int i=0;i<n;i++) map0[heights[i]]=i;
      stack<int>stack0;
      stack0.push(heights[n-1]);
      for(int i=n-2;i>=0;i--){
        if(heights[i]<=stack0.top()) continue;
        else stack0.push(heights[i]);
      }
      vector<int>ans;
      //cout<<stack0.size()<<endl;
      while(!stack0.empty()){
        ans.push_back(map0[stack0.top()]);
        stack0.pop();
      }
      return ans;
    }
};
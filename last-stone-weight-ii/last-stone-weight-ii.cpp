class Solution {
  public:
  int lastStoneWeightII(vector<int>& stones) {
    unordered_set<int>combo{0};
    for(int stone:stones){
      unordered_set<int>tmp;
      for(int x:combo){
        tmp.insert(x+stone);
        tmp.insert(x-stone);
      }
      combo=move(tmp);
      //for(int i:combo) cout<<i<<" ";cout<<endl;
    }
    int ans=INT_MAX;
    for(int i:combo){
      if(i>=0) ans=min(ans,i);
    }
    return ans;
  }
};
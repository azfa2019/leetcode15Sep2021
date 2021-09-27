class Solution {
public:
    int minimizeTheDifference(vector<vector<int>>& mat, int target) {
      
      int m=mat.size(),n=mat[0].size();
      unordered_set<int>cap{0};
      for(int i=0;i<m;i++){
        unordered_set<int>tmp;
        int great=-1;
        for(int x:cap){
          for(int y:mat[i]){
            if(x+y<=target) tmp.insert(x+y);
            else{
              if(great==-1||great>x+y) great=x+y;
            }
          }
        }
        if(great!=-1) tmp.insert(great);
        cap=std::move(tmp);
      }
      int diff=INT_MAX;
      for(int i:cap)
        diff=min(diff,abs(i-target));
      return diff;
    }
};
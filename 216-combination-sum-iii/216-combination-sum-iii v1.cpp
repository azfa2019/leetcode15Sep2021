class Solution {
    vector<int>cur;
    vector<vector<int>>res;
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        dfs(1,n,k,n);
        return res;
    }
    void dfs(int curNum,int remain,int k,int n){
        if(cur.size()==k){
            if(remain==0) {
                res.push_back(cur);
                return;
            }
        }
        for(int i=curNum;i<=9;i++){
            cur.push_back(i);
            dfs(i+1,remain-i,k,n);
            cur.pop_back();
        }
    }
};

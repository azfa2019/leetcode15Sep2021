class Solution {
public:
    int maxProduct(vector<string>& words) {
        vector<int>state;
        for(auto w:words){
            int u=0;
            for(auto c:w){
                u|=(1<<(c-'a'));
            }
            state.push_back(u);
        }
        int res=0;
        for(int i=0;i<words.size();i++)
            for(int j=0;j<i;j++)
                if((state[i]&state[j])==0) res=max(res,(int)(words[i].size()*words[j].size()));
            
        return res;
    }
};
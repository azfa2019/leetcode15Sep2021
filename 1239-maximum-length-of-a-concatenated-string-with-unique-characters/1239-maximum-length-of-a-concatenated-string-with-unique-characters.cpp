class Solution {
public:
    int maxLength(vector<string>& arr) {
        vector<int>state;
        int n=arr.size();
        for(auto& str:arr){
            int s=0;
            for(auto& c:str){
                int t=c-'a';
                if(s>>t&1) {s=-1;break;}
                s|=1<<t;
            }
            state.push_back(s);
        }
        int res=0;
        for(int i=0;i<1<<n;i++){
            int s=0,len=0;
            for(int j=0;j<n;j++){
                if(i>>j&1){
                    if(state[j]==-1||s&state[j]) {len=-1;break;}
                    len+=arr[j].size();
                    s|=state[j];
                }
            }
            res=max(res,len);
        }
        return res;
    }
};
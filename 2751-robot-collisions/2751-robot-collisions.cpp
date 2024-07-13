class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& p, vector<int>& h, string d) {
        int n=p.size(),id[n];
        iota(id,id+n,0);
        sort(id,id+n,[&](const int i,const int j){
            return p[i]<p[j];
        });
        stack<int>st;
        for(int i:id){
            if(d[i]=='R'){
                st.push(i);
                continue;
            }
            while(st.size()){
                int top=st.top();
                if(h[top]>h[i]){
                    h[top]--;
                    h[i]=0;
                    break;
                }
                if(h[top]==h[i]){
                    h[top]=0;
                    st.pop();
                    h[i]=0;
                    break;
                }
                h[top]=0;
                st.pop();
                h[i]--;
            }
        }
        h.erase(remove(h.begin(),h.end(),0),h.end());
        return h;
    }
};
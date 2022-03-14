class Solution {
    public:
    string simplifyPath(string path) {
        int n=path.size();
        vector<string>res;
        for(int i=0;i<n;){
            string cur="";
            int j=i+1;
            while(j<n && path[j]!='/') cur+=path[j++];
            if(cur.size()) res.push_back(cur);
            i=j;
        }
        stack<string>st;
        for(int i=0;i<res.size();i++){
            if(res[i]=="..") {
                if(st.size()) st.pop();
            }else if(res[i]==".") continue;
            else st.push(res[i]);
        }
        string ans="";
        while(st.size()){
            ans='/'+st.top()+ans;
            st.pop();
        }
        return ans==""?"/":ans;
    }
};
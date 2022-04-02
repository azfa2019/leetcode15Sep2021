class Solution {
public:
    vector<string> expand(string s) {
        int n=s.size();
        vector<string>letters;
        int i=0;
        while(i<n){
            if(s[i]=='{'){
                i++;
                letters.push_back("");
                while(s[i]!='}'){
                    if(s[i]==',') {
                        i++;
                        continue;
                    }
                    letters.back().push_back(s[i++]);
                }
                i++;
            }else letters.push_back(""),letters.back()+=s[i++];
        }
        vector<string> ans;
        string cur="";
        dfs(letters,ans,cur,0);
        sort(ans.begin(),ans.end());
        return ans;
    }
    void dfs(vector<string>& letters,vector<string>&ans,string& cur, int pos){
        if(pos==letters.size()){
            ans.push_back(cur);
            return;
        }
        for(char c:letters[pos]){
            cur.push_back(c);
            dfs(letters,ans,cur,pos+1);
            cur.pop_back();
        }
    }
};
class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        unordered_map<string,vector<string>>hash;
        for(auto& path:paths){
            stringstream ss(path);
            string p,file,name,content;
            ss>>p;
            while(ss>>file){
                int x=file.find('('),y=file.find(')');
                name=file.substr(0,x);
                content=file.substr(x+1,y-x-1);
                hash[content].push_back(p+'/'+name);
            }
        }
        vector<vector<string>>res;
        for(auto&[k,v]: hash){
            if(v.size()>1) res.push_back(v);
        }
        return res;
    }
};
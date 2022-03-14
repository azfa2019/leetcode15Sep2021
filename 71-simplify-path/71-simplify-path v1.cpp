class Solution {
public:
    string simplifyPath(string path) {
        string res,cur;
        if(path.back()!='/') path=path+'/';
        for(auto c:path){
            if(c!='/') cur+=c;
            else{
                if(cur==".."){
                    while(res.size() && res.back()!='/') res.pop_back();
                    if(res.size()) res.pop_back();
                }else if(cur!="." && cur!="") res+='/'+cur;
                cur.clear();
            }
        }
        if(res.empty()) res="/";
        return res;
    }
};

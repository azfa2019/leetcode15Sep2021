class FileSystem {
    unordered_map<string,int>paths;
public:
    FileSystem() {
        
    }
    
    bool createPath(string path, int value) {
        if(paths.count(path)) return false;
        string cur;
        for(int i=0;i<path.size();i++){
            if(i==0||path[i]!='/') cur+=path[i];
            else if(i!=0 && path[i]=='/'){
                if(paths.count(cur)==0) return false;
                else cur+=path[i];
            }
        }
        paths[path]=value;
        return true;
    }
    
    int get(string path) {
        if(!paths.empty() && paths.count(path)) return paths[path];
        return -1;
    }
};

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem* obj = new FileSystem();
 * bool param_1 = obj->createPath(path,value);
 * int param_2 = obj->get(path);
 */
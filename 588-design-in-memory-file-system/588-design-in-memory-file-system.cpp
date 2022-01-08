class FileSystem {
    struct Node {
        bool isFile;
        unordered_map<string,Node*>next;
        string content;
        Node():isFile(false),content(""){}
    };
    Node* root;
public:
    FileSystem() {
        root=new Node();
    }
    Node* gotoPath(string path){
        Node* cur=root;
        stringstream ss(path);
        string folder;
        while(getline(ss,folder,'/')){
            if(folder.size()){
                if(cur->next[folder]==nullptr) cur->next[folder]=new Node();
                cur=cur->next[folder];
            }
        }
        return cur;
    }
    vector<string> ls(string path) {
        Node* cur=gotoPath(path);
        if(cur->isFile) return {path.substr(path.find_last_of('/')+1)};
        vector<string>ans;
        for(auto e:cur->next) ans.push_back(e.first);
        sort(ans.begin(),ans.end());
        return ans;
    }
    
    void mkdir(string path) {
        gotoPath(path);
    }
    
    void addContentToFile(string filePath, string content) {
        Node* cur=gotoPath(filePath);
        cur->content+=content;
        cur->isFile=true;
    }
    
    string readContentFromFile(string filePath) {
        Node* cur=gotoPath(filePath);
        return cur->content;
    }
};

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem* obj = new FileSystem();
 * vector<string> param_1 = obj->ls(path);
 * obj->mkdir(path);
 * obj->addContentToFile(filePath,content);
 * string param_4 = obj->readContentFromFile(filePath);
 */
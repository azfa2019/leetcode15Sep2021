class LRUCache {
public:
    struct Node{
        int val,key;
        Node* left,*right;
        Node(int _key,int _val): key(_key),val(_val),left(NULL),right(NULL){}}*L,*R;
        unordered_map<int,Node*>hash;
        int n;
    
    void remove(Node* p){
        p->right->left=p->left;
        p->left->right=p->right;
    }
    void insert(Node* p){
        p->right=L->right;
        p->left=L;
        L->right->left=p;
        L->right=p;
    }
    LRUCache(int capacity) {
        n=capacity;
        L=new Node(-1,-1),R=new Node(-1,-1);
        L->right=R,R->left=L;
    }
    
    int get(int key) {
        if(!hash.count(key)) return -1;
        auto p=hash[key];
        remove(p);
        insert(p);
        return p->val;
    }
    
    void put(int key, int value) {
        if(hash.count(key)){
            auto p=hash[key];
            p->val=value;
            remove(p);
            insert(p);
        }else{
            if(hash.size()==n){
                auto p=R->left;
                remove(p);
                hash.erase(p->key);
                delete p;
            } 
            auto p=new Node(key,value);
            hash[key]=p;
            insert(p);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
class Vector2D {
    vector<vector<int>>data;
    int x,y;
public:
    Vector2D(vector<vector<int>>& vec):data(vec),x(0),y(0) {
        
    }
    
    int next() {
        hasNext();
        return data[x][y++];
    }
    
    bool hasNext() {
        while(x<data.size()&&y==data[x].size())
            x++, y=0;
        return x<data.size();
    }
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D* obj = new Vector2D(vec);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
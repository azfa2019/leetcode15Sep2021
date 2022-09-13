class Solution {
public:
    int get(int x,int k){
        return x>>k&1;
    }
    bool validUtf8(vector<int>& data) {
        for(int i=0;i<data.size();i++){
            if(!get(data[i],7)) continue;
            int k=0;
            while(k<=4 && get(data[i],7-k)) k++;
            if(k==1||k>4) return false;
            for(int j=0;j<k-1;j++){
                int t=i+1+j;
                if(t>=data.size()) return false;
                if(! (get(data[t],7) && !get(data[t],6))) return false;
            }
            i+=k-1;
        }
        return true;
    }
};
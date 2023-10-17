    const int N=1e4+7;
class Solution {
public:

        int p[N];
        int find(int x){
            if(p[x]!=x) p[x]=find(p[x]);
            return p[x];
        }
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        for(int i=0;i<n;i++) p[i]=i;
        for(int i=0;i<n;i++){
            int l=leftChild[i];
            if(l!=-1){
                int pa=find(i),pb=find(l);
                if(pa==pb) return false;
                else{
                    if(pb==l) p[pb]=pa;
                    else return false;
                }
            }
            int r=rightChild[i];
            if(r!=-1){
                int pa=find(i),pb=find(r);
                if(pa==pb) return false;
                else{
                    if(pb==r) p[pb]=pa;
                    else return false;
                }
            }
        }
        int ans=0;
        for(int i=0;i<n;i++) if(p[i]==i) ans++;
        return ans==1;
    }
};
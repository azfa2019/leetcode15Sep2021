class Solution {
public:
    int findComplement(int num) {
        int s;
        for(int i=31;i>=0;i--){
            if((num>>i)&1!=0) {
                s=i;
                break;
            }
        }
        int ans=0;
        for(int i=0;i<s;i++){
            if(((num>>i)&1)==0) ans|= (1<<i);
        }
        return ans;
    }
};
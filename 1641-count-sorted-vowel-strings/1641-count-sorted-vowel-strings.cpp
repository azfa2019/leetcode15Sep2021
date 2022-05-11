class Solution {
public:
    int countVowelStrings(int n) {
        vector<int>arr(5,1);
        vector<int>copy(5);
        int sum=5;
        for(int i=2;i<=n;i++){
            copy[0]=sum;
            for(int j=1;j<5;j++) copy[j]=copy[j-1]-arr[j-1];
            sum=0;
            for(int j=0;j<5;j++) sum+=copy[j];
            arr=copy;
        }
        return sum;
    }
};
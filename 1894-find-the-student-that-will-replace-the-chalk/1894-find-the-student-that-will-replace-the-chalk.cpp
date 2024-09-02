class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int n=chalk.size();
        long long s=0;
        for(auto&c:chalk) s+=c;
        //long long s=accumulate(chalk.begin(),chalk.end(),0); 
        long long kk=k%s;
        while(true){
            for(int i=0;i<n;i++){
                kk-=chalk[i];
                if(kk<0) return i;
            }
        }
        return 0;
    }
};
class Solution {
public:
    int maximumUnits(vector<vector<int>>& box, int truckSize) {
        sort(box.begin(),box.end(),[](vector<int>&a,vector<int>&b){
            return a[1]>b[1];
        });
        int sum=0;
        for(int i=0;i<box.size();i++){
            while(truckSize>0&& box[i][0]>0){
                sum+=box[i][1];
                truckSize--;
                box[i][0]--;
            }
        }
        return sum;
             
    }
};
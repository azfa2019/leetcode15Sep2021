class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int i=0,t=0;
        while(t<k && i<arr.size()){
            if(arr[i]>arr[i+1]){
                arr[i+1]=arr[i];
                t++;
            }else t=1;
            i++;
        }
        return arr[i];
    }
};
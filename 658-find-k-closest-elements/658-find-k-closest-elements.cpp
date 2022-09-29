class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int t) {
        int l=0,r=arr.size()-1;
        while(l<r){
            int mid=l+r>>1;
            if(arr[mid]>=t) r=mid;
            else l=mid+1;
        }
        if(r){
            int x=arr[r-1],y=arr[r];
            if(make_pair(abs(x-t),x)<make_pair(abs(y-t),y)) r--;
        }
        int i=r,j=r;
        for(int u=0;u<k-1;u++){
            if(i-1<0) j++;
            else if(j+1>arr.size()-1) i--;
            else{
                int x=arr[i-1],y=arr[j+1];
                pair<int,int> a{abs(t-x),x},b{abs(t-y),y};
                if(a<b) i--;
                else j++;
            }
        }
        vector<int>res;
        for(int u=i;u<=j;u++) res.push_back(arr[u]);
        return res;

    }
};
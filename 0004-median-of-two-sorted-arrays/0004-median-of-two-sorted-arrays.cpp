class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int tot=nums1.size()+nums2.size();
        if(tot%2==0){
            int left=findk(nums1,0,nums2,0,tot/2);
            int right=findk(nums1,0,nums2,0,tot/2+1);
            return (left+right)/2.0;
        }else return findk(nums1,0,nums2,0,tot/2+1);
        
    }
    int findk(vector<int> &nums1, int i, vector<int> &nums2, int j, int k)
    {
        if (nums1.size() - i > nums2.size() - j) return findk(nums2, j, nums1, i, k);
        if (nums1.size() == i) return nums2[j + k - 1];
        if (k == 1) return min(nums1[i], nums2[j]);
        int si = min(i + k / 2, int(nums1.size())), sj = j + k / 2;
        if (nums1[si - 1] > nums2[sj - 1])
        {
            return findk(nums1, i, nums2, j + k / 2, k - k / 2);
        }
        else
        {
            return findk(nums1, si, nums2, j, k - (si - i));
        }
    }
};
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if((nums1.size() + nums2.size()) == 0)
        	return 0;
        return(fineMed(nums1,0,nums1.size(), nums2,0,nums2.size()));
    }

    int fineMed(vector<int>&  nums1, int a1, int a2, vector<int>& nums2, int b1, int b2)
    {
    	int m = nums1.size();
    	int n = nums2.size();
    	int k = (m+n)/2;
    	if (m == 0 && n != 0)
    		return (nums2[n/2]);
    	else if(n == 0)
    		return (nums1[m/2]);
    	else if(k == 1)
    		return(min(nums1[0], nums2[0]));

    	int indexA = min(k/2, m);
    	int indexB = n - indexA;

    	if(nums1[indexA] < nums2[indexB])
    		return(fineMed(nums1, indexA+1, m, nums2, 0, indexB-1));
    	else if (nums1[indexA] > nums2[indexB])
    		return(fineMed(nums1, 0, indexA-1, nums2, indexB,n));
    	else
    		return(nums1[indexA]);
    }
};
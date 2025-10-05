// Approach 1---- using the sort function

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        nums1.insert(nums1.end(),nums2.begin(),nums2.end());
        int n= nums1.size();
        sort(nums1.begin(),nums1.end());
        if(n%2 !=0){
            return nums1[n/2];
        }
        else{
            return (nums1[(n-1)/2] + nums1[n/2])/2.0;
        }
    }
};

// Approach 2---- using the optinal approach in binary search




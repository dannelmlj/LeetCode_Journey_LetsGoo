class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int size1 = nums1.size();
        int size2 = nums2.size();
        int total = size1 + size2;

        bool even = false;
        if (total % 2 == 0){
            even = true;
        }
        int mid = total/2;
        
        if (size1 == 0){
            if (even) return ((double)nums2[mid] + (double)nums2[mid-1]) /2;
            return (double)nums2[mid];
        } else if (size2 == 0){
            if (even) return ((double)nums1[mid] + (double)nums1[mid-1]) /2;
            return (double)nums1[mid];
        }

        vector<int> combined(mid+1);

        int idx1 = 0;
        int idx2 = 0;

        for (int i=0; i<=mid; i++){

            if (idx1 >= size1 || idx2 >= size2){
                if (i == mid){
                    if (idx1 >= size1){
                        if (even) return ((double)combined[i-1] + (double)nums2[idx2]) / 2;
                        return (double)nums2[idx2];
                    } else {
                        if (even) return ((double)combined[i-1] + (double)nums1[idx1]) / 2;
                        return (double)nums1[idx1];
                    }
                } else {
                    if (idx1 >= size1){
                        if (even) return ((double)nums2[mid - i + idx2] + (double)nums2[mid - i + idx2 - 1]) / 2;
                        return (double)nums2[mid - i + idx2];
                    } else {
                        if (even) return ((double)nums1[mid - i + idx1] + (double)nums1[mid - i + idx1 - 1]) / 2;
                        return (double)nums1[mid - i + idx1];
                    }
                }
            }
            if (nums1[idx1] < nums2[idx2]){
                combined[i] = nums1[idx1];
                idx1++;
            } else {
                combined[i] = nums2[idx2];
                idx2++;
            }
        }

        for (auto i : combined){
            cout << i << ' ';
        }

        if (even){
            return ((double)combined[mid - 1] + (double)combined[mid] )/ 2;
        }
        return (double)combined[mid];
    }
};
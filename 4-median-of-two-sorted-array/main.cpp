class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        if (m > n) {
            std::swap(nums1, nums2);
            std::swap(m, n);
        }
        int rank = (m + n + 1) / 2;
        int l = 0, r = m;
        int i, j;
        while (l <= r) {
            i = (l + r) / 2;
            j = rank - i;
            if (i > l && nums1[i-1] > nums2[j]) {
                r = i - 1;
            } else if (i < r && nums2[j-1] > nums1[i]) {
                l = i + 1;
            } else{
                break;
            }
        }

        int maxLeft, minRight;
        if (i == 0) {
            maxLeft = nums2[j-1];
        } else if (j == 0) {
            maxLeft = nums1[i-1];
        } else {
            maxLeft = std::max(nums1[i-1], nums2[j-1]);
        }

        if (i == m) {
            minRight = nums2[j];
        } else if (j == n) {
            minRight = nums1[i];
        } else {
            minRight = std::min(nums1[i], nums2[j]);
        }

        if ((n + m) % 2 == 0) {
            return (maxLeft + minRight) / 2.0;
        } else {
            return maxLeft;
        }
    }
};
